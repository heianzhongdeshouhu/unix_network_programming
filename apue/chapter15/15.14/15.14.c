/*
 * please refer to the page in 547.
 */

#include "apue.h"
#include <ctype.h>

int 
main(int argc, char *argv[]) {
    int     c;
    while (EOF != (c = getchar())) {
        if (isupper(c)) {
            c = tolower(c);
        }
        if (EOF == putchar(c)) {
            err_sys("output error");
        }
        if ('\n' == c) {
            fflush(stdout);
        }
    }

    exit(0);
}
