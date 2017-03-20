#include <stdio.h>
#include <sys/select.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include <fcntl.h>  /* for nonblocking */

#include <unistd.h>
#include <stdarg.h>

#include <stdlib.h>
#include <errno.h>

#include <poll.h>

#include <sys/time.h>   /* timeval{} for select() */

/*
 * Posix.1g requires that an #include of <poll.h> DefinE INFTIM, but many
 * systems still DefinE it in <sys/stropts.h>. We don't want to include
 * all the streams stuff if it's not needed, so we just DefinE INFTIM here.
 * This is the standard value, but there's no guarantee it is -1.
 */
#ifndef INFTIM
#define INFTIM  (-1) /* infinite poll timeout */
/* $$.Ic INFTIM$$ */
#ifdef HAVE_POLL_H
#define INFTIM_UNPH /* tell unpxti.h we defined it */
#endif
#endif

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
 * kernels stills #define it as 5, while actually supporting many more
 */
#define LISTENQ     1024        /* 2nd argument to listen() */

/* Miscellaneous constants */
#define MAXLINE     4096    /* max text line length */

#define SERV_PORT        9877           /* TCP and UDP client-servers */

#define max(a,b)    ((a) > (b) ? (a) : (b))

void    err_quit(const char *, ...);
void err_sys(const char *fmt, ...);

#define SA  struct sockaddr

void    str_cli(FILE *, int);




int      Socket(int, int, int); 
int Accept(int, struct sockaddr *, socklen_t *);

void Bind(int, const struct sockaddr *, socklen_t);
void Listen(int, int);
//#ifdef HAVE_POLL
int Poll(struct pollfd *, unsigned long, int);
//#endif

int Select(int, fd_set *, fd_set *, fd_set *, struct timeval *);

ssize_t Read(int, void *, size_t);
void Write(int, void *, size_t);

void Close(int);




/* prototypes for our own library functions */
char * gf_time(void); 
void    str_echo(int);

/* prototypes for our own Unix wrapper functions: see (Sec errors) */
int Fcntl(int, int, int);
pid_t Fork(void);

/* prototypes for our stdio wrapper functions: see {Sec errors} */
char    *Fgets(char *, int, FILE *);
void Fputs(const char *, FILE *);

/* prototypes for our own socket wrapper functions: see {Sec errors} */
void Shutdown(int, int);
void Writen(int , void *, size_t );

ssize_t Readline(int , void *, size_t );
