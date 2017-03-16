/*
 * please refer to the code in page 100.
 */
#include "unp.h"

int main(int argc, char *argv[]) {
    int     sockfd;
    struct sockaddr_in serveraddr;

    if (2 != argc) {
        err_quit("usage: tcpcli <IPaddress>");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    connect(sockfd, (SA *)&serveraddr, sizeof(serveraddr));

    str_cli(stdin, sockfd);     /* do it all */

    exit(0);
}
