#include "apue.h"

#define PAGER   "${PAGER:-more}"    /* environment variable, or default */

int main(int argc,char *argv[]) {
    char    line[MAXLINE];
    FILE    *fpin, *fpout;

    if (2 != argc) {
        err_quit("usage: a.out <pathname>");
    }
    if (NULL == (fpin = fopen(argv[1], "r"))) {
        err_sys("can't open %s", argv[1]);
    }

    if (NULL == (fpout= popen(PAGER, "w"))) {
        err_sys("popen error");
    }

    /* copy argv[1] to pager */
    while (NULL != fgets(line, MAXLINE, fpin)) {
        if (EOF == fputs(line, fpout)) {
            err_sys("fputs error to EOF");
        }
    }
    if (ferror(fpin)) {
        err_sys("fgets error");
    }
    if (-1 == pclose(fpout)) {
        err_sys("pclose error");
    }

    exit(0);
}
