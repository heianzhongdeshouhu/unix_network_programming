/*
 * Standard I/O wrapper functions.
 */

#include "unp.h"

char *
Fgets(char *ptr, int n, FILE *stream) {
    char    *rptr;

    if (NULL == (rptr = fgets(ptr, n, stream)) && ferror(stream)) {
        err_sys("fgets error");
    }

    return (rptr);
}

void
Fputs(const char *ptr, FILE *stream) {
    if (EOF == fputs(ptr, stream)) {
        err_sys("fputs error"); 
    }
}
