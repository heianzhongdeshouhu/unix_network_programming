#include "unp.h"

void
str_cli(FILE *fp, int sockfd) {
    char    sendline[MAXLINE], recvline[MAXLINE];

    while (NULL != Fgets(sendline, MAXLINE, fp)) {
        
        Writen(sockfd, sendline, strlen(sendline));

        if (0 != Readline(sockfd, recvline, MAXLINE)) {
            err_quit("str_cli: server terminated prematurely");
        }

        Fputs(recvline,  stdout);
    }

}
