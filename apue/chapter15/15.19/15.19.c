/*
 * please refer to the code in page 551.
 */

#include "apue.h"

int
main(int argc, char *argv[]) {
    int     int1, int2;
    char    line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (sscanf(line, "%d%d", &int1, &int2) == 2) {
            if (printf("%d\n", int1 + int2) == EOF) {
                err_sys("printf error");
            }
        } else {
            if (printf("invalid args\n") == EOF) {
                err_sys("printf error");
            }
        }
    }

    exit(0);
}
