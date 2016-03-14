/*
 * Socket wrapper functions.
 * These could all go into separate files, so only the ones needed cause
 * the corresponding functions to be added to the executable. If sockets
 * are a library (SVR4) this might make a difference (?), but if sockets
 * are in the kernel(BSD) it doesn't matter.
 *
 * These wrapper functions also use the same prototypes as POSIX.lg,
 * which might differ from many implementation (i.e., POSIX.1g specifies
 * the fourth argument to getsockopt() as "void *", not "char *").
 *
 * If your system's headers are not correct [i.e., the Solaris 2.5
 * <sys/socket.h> omits the "const" from the second argument to both
 * bind() and connect()], you'll get warning of the form:
 *  warning: passing arg 2 of 'bind' discards 'const' from pointer target type
 *  warning: passing arg 2 of 'connect' discards 'const' from pointer target type
 */

#include "unp.h"

void *
Calloc(size_t n, size_t size)
{
    void *ptr;

    if ((ptr = calloc(n, size)) == NULL)
//        err_sys("calloc error");
        printf("calloc error");
    return (ptr);    
}

void Gettimeofday(struct timeval *tv, void *foo)
{
    if (gettimeofday(tv, foo) == -1)
    {
//        err_sys("gettimeofday error");
        printf("gettimeofday error");
    }
    return;
}
