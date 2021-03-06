#include "unp.h"

void
str_cli(FILE *fp, int sockfd) {
    int     maxfdp1, stdineof;
    fd_set  rset;
    char    buf[MAXLINE];
    int     n;

    stdineof = 0;
    FD_ZERO(&rset);
    for ( ; ; ) {
        if (stdineof == 0) {
            FD_SET(fileno(fp), &rset);
        }

        FD_SET(sockfd, &rset);
        maxfdp1 = max(fileno(fp), sockfd) + 1;
        select(maxfdp1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset)) {
            if ((n = read(sockfd, buf, MAXLINE)) == 0) {
                if (stdineof == 1) {
                    return;         /* normal termination */ 
                }
                else {
                    err_quit("str_cli: server terminated prematurely"); 
                }
            }

            write(fileno(stdout), buf, n);
        }

        if (FD_ISSET(fileno(fp), &rset)) {
            if ((n = read(fileno(fp), buf, MAXLINE)) == 0) {
                stdineof = 1;
                shutdown(sockfd, SHUT_WR);
                FD_CLR(fileno(fp), &rset);
                continue;
            } 

            write(sockfd, buf, n);
        }
    }
}
