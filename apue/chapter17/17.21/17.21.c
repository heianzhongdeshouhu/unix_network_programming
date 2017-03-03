#include "apue.h"

char    errmsg[MAXLINE];
int     oflag;
char    *pathname;

int
main(int argc, char *argv[]) {
    
    int     nread;
    char    buf[MAXLINE];

    for ( ; ; ) {       /* read arg buffers from client, process request */
        if ((nread = read(STDIN_FILENO, buf, MAXLINE)) < 0) {
            err_sys("read error on stream pipe");
        } else if (0 == nread) {
            break;      /* client has closed the stream pipe */
        }
        handle_request(buf, nread, STDOUT_FILENO);
    }

    exit(0);
}
