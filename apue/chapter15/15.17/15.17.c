#include "apue.h"

int 
main(int argc, char *argv[]) {
    int     int1, int2;
    char    line[MAXLINE];

    while (NULL != fgets(line, MAXLINE, stdin)) {
        if (2 == sscanf(line, "%d%d", &int1, &int2)) {
            if (EOF == printf("%d\n", int1 + int2)) {
                err_sys("printf error");
            }
        } else {
            if (EOF == printf("invalid args\n")) {
                err_sys("printf error");
            }
        }
    }


    exit(0);
}
