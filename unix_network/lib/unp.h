#include <signal.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <stdlib.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/un.h>
#include <sys/time.h>
#include <stdarg.h>

/* Miscellaneous constants */
#define MAXLINE     4096    /* max text line length */
#define BUFFSIZE    8192    /* buffer size for reads and writes */

void     Gettimeofday(struct timeval *, void *);

char *
Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);


typedef void Sigfunc(int);      /* for signal handlers */

Sigfunc *
Signal(int signo, Sigfunc *func);

struct addrinfo *
Host_serv(const char *host, const char *serv, int family, int socktype);

void *Calloc(size_t n, size_t size);

void readloop(void);

uint16_t
in_cksum(uint16_t *addr, int len);

void
Sendto(int fd, const void *ptr, size_t nbytes, int flags,
    const struct sockaddr *sa, socklen_t salen);

int
Socket(int family, int type, int protocol);

void    err_quit(const char *fmt, ...);
void    err_sys(const char *fmt, ...);

uint16_t in_cksum(uint16_t *addr, int len);
void     tv_sub (struct timeval *out, struct timeval *in);
