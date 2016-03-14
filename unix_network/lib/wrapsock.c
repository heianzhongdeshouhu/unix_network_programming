/*
 * Socket wrapper functions.
 * These could all go into seperate files, so only the ones needed cause
 * the corresponding functions to be added to the executable. If sockets
 * are a library (SVR4) this might make a difference (?), but if sockets
 * are in the kernel (BSD) it doesn't matter.
 *
 * These wrapper functions alse use the same prototypes as POSIX.1g,
 * which might differ from many implementations (i.e., POSIX.1g specifies
 * te fourth argument to getsockopt() as "void *", not "char *").
 *
 * If your system's headers are not correct[i.e., the Solaris 2.5
 * <sys/socket.h> omits the "const" from the second argument to both
 * bind() and connect()], you'll get warnings of the form:
 *  warning: passing arg 2 of 'bind' discards 'const' from pointer target type
 *  warning: passing arg 2 of 'connect' discards 'const' from pointer target type
 */
#include "unp.h"

void
Sendto(int fd, const void *ptr, size_t nbytes, int flags,
    const struct sockaddr *sa, socklen_t salen)
{
    if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
//        err_sys("sendto error");
        printf("sendto error");
}

/* include Socket */
int
Socket(int family, int type, int protocol)
{
    int     n;
    
    if ((n = socket(family, type, protocol)) < 0)
        err_sys("socket error");
    return (n);    
}
/* end Socket */


