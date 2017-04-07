#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>

#include <stdio.h>

#define MAXEVENTS 64

static int
create_and_bind(char *port) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s, sfd;

    memset(&hints, 0, sizeof (struct addrinfo));
    hints.ai_family     = AF_UNSPEC;    /* Return IPv4 and IPv6 choices */
    hints.ai_socktype   = SOCK_STREAM;  /* We want a TCP socket */
    hints.ai_flags       = AI_PASSIVE;   /* All interfaces */

    s = getaddrinfo(NULL, port, &hints, &result);
    if (0 != s) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    for (rp = result; NULL != rp; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (-1 == sfd) {
            continue;
        }

        s = bind(sfd, rp->ai_addr, rp->ai_addrlen);
        if (0 == s) {
            /* We managed to bind successfully! */
            break;
        }

        close(sfd);
    }

    if (NULL == rp) {
        fprintf(stderr, "Could not bind\n");
        return -1;
    }

    freeaddrinfo(result);

    return sfd;
}

static int
make_socket_non_blocking(int sfd) {
    int flags, s;

    flags = fcntl(sfd, F_GETFL, 0);
    if (-1 == flags) {
        perror("fcntl");
        return -1;
    }

    flags |= O_NONBLOCK;
    s = fcntl(sfd, F_SETFL, flags);
    if (-1 == s) {
        perror("fcntl");
        return -1;
    }
    return 0;
}

int
main(int argc, char *argv[]) {
    int sfd, s;
    int efd;
    struct epoll_event event;
    struct epoll_event *events;

    if (2 != argc) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sfd = create_and_bind(argv[1]);
    if (-1 == sfd) {
        abort();
    }

    s = make_socket_non_blocking(sfd);
    if (-1 == s) {
        abort();
    }

    s = listen(sfd, SOMAXCONN);
    if (-1 == s) {
        perror("listen");
        abort();
    }

    efd = epoll_create1(0);
    if (-1 == efd) {
        perror("epoll_create1");
        abort();
    }

    event.data.fd = sfd;
    event.events = EPOLLIN| EPOLLET;
    s = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);
    if (-1 == s) {
        perror("epoll_ctl");
        abort();
    }

    /* Buffer where events are returned */
    events = calloc(MAXEVENTS, sizeof event);

    /* The event loop */
    while (1) {
        int n, i;

        n = epoll_wait(efd, events, MAXEVENTS, -1);
        for (i = 0; i < n; i++) {
            if ( (events[i].events & EPOLLERR) ||
                    (events[i].events & EPOLLHUP) ||
                    (!(events[i].events & EPOLLIN))) {
                /* An error has occured on this fd, or the socket is not
                 * ready for reading (why were we nofified then?)
                 * */
                fprintf(stderr, "epoll error\n");
                close(events[i].data.fd);
                continue;

            } else if (sfd == events[i].data.fd) {
                /* We have a notification on the listening socket, which 
                 * means one or more incomming connections.
                 */
                while (1) {
                    struct sockaddr in_addr;
                    socklen_t in_len;
                    int infd;
                    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];

                    in_len = sizeof in_addr;
                    infd = accept(sfd, &in_addr, &in_len);
                    if (-1 == infd) {
                        if ((EAGAIN == errno) || (EWOULDBLOCK == errno)) {
                            /* We have processed all incoming connections.
                            */
                            break;
                        } else {
                            perror("accept");
                            break;
                        }
                    }

                    s = getnameinfo(&in_addr, in_len,
                            hbuf, sizeof hbuf,
                            sbuf, sizeof sbuf,
                            NI_NUMERICHOST | NI_NUMERICSERV);
                    if (0 == s) {
                        printf("Accept connection on descriptor %d "
                                "(host=%s, port=%s)\n", infd, hbuf, sbuf);
                    }                

                    /* Make the incomming socket non-blocking and add it to the 
                     * list of fds to monitor.
                     */
                    s = make_socket_non_blocking(infd);
                    if (-1 == s) {
                        abort();
                    }

                    event.data.fd = infd;
                    event.events = EPOLLIN | EPOLLET;
                    s = epoll_ctl(efd, EPOLL_CTL_ADD, infd, &event);
                    if (-1 == s) {
                        perror("epoll_ctl");
                        abort();
                    }
                }
                continue;
            } else {
                /* We have data on the fd waiting to be read. Read and 
                 * display it. We must read whatever data is available
                 * completely, as we are running in edge-triggered mode
                 * and won't get a notification again for the same
                 * data. */
                int done = 0;

                while (1) {
                    ssize_t count;
                    char buf[512];

                    count = read(events[i].data.fd, buf, sizeof buf);
                    if (-1 == count) {
                        /* If errno = EAGAIN, that means we have read all
                         * data. So go back to the main loop. */
                        if (EAGAIN !=errno) {
                            perror("read");
                            done = 1;
                        }
                        break;
                    } else if (0 == count) {
                        /* End of file. The remote has closed the 
                         * connection. */
                        done = 1;
                        break;
                    }

                    /* Write the buffer to standard output */
                    s = write(1, buf, count);
                    if (-1 == s) {
                        perror("write");
                        abort();
                    }
                }

                if (done) {
                    printf("Closed connection on descriptor %d\n",
                            events[i].data.fd);

                    /* Closing the descriptor will make epoll remove it
                     * from the set of descriptors which are monitored. */
                    close(events[i].data.fd);
                }
            }
        }
    }

    free(events);

    close(sfd);

    return EXIT_SUCCESS;

    //exit(0);
}
