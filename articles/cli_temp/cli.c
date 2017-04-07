#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#define MYPORT          8887
#define BUFFER_SIZE     1024

int main(int argc, char *argv[]) {
    int sock_cli = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char sendbuf[BUFFER_SIZE];
    char recvbuf[BUFFER_SIZE];

    while (NULL != fgets(sendbuf, sizeof(sendbuf), stdin)) {
        send(sock_cli, sendbuf, strlen(sendbuf), 0);
        if (0 == strcmp(sendbuf, "exit\n")) {
            break;
        }

        memset(sendbuf, 0, sizeof(sendbuf));
    }
    close(sock_cli);

    exit(0);
}
