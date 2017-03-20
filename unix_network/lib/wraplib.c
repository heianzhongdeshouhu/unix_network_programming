/*
 * Wrapper functions for our own library functions.
 * Most are included in the source file ofr the functions itself.
 */

#include "unp.h"

const char *
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len) {
    const char *ptr;

    if (NULL == strptr) {               /* check for old code */
        err_quit("NULL 3rd argument to inet_ntop");
    }
    if (NULL == (ptr = inet_ntop(family, addrptr, strptr, len))) {
        err_sys("inet_ntop error");     /* sets errno */
    }

    return (ptr);
}

void
Inet_pton(int family, const chaar *strptr, void *addrptr) {
    int     n;

    if ( (n = inet_pton(family, strptr, addrptr)) < 0) {
        err_sys("inet_pton error for %s", strptr);  
    }
}
