/*
 * please refer to the code in page 548.
 */ 

#include "apue.h"

int 
main(int argc, char *argv[]) {
    char    line[MAXLINE];
    FILE    *fpin;

    if (NULL == (fpin = popen("myuclc", "r"))) {
        err_sys("popen error");
    }
    for ( ; ; ) {
        fputs("prompt> ", stdout);
        fflush(stdout);
        if (fgets(line, MAXLINE, fpin) == NULL) {       /* read from pipe */
            break;
        }
        if (EOF == fputs(line, stdout)) {
            err_sys("fputs error to pipe");
        }
    }
    if (-1 == pclose(fpin)) {
        err_sys("pclose error");
    }
    putchar('\n');

    exit(0);
}
