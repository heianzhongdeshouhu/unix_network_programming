#include "unp.h"

void str_echo(int socketfd) {
    ssize_t         n;
    char            buf[MAXLINE];

again:
    while ( (n = read(socketfd, buf, MAXLINE)) > 0) {
        Writen(socketfd, buf, n); 
    }

    if (n < 0 && EINTR == errno) {
        goto again; 
    } else if (n < 0) {
        err_sys("str_echo: read error"); 
    }
}
