#include "unp.h"

void
Close(int fd) {
    if (-1 == close(fd)) {
        err_sys("close error");
    }
}

ssize_t
Read(int fd, void *ptr, size_t nbytes) {
    ssize_t     n;

    if (-1 == (n = read(fd, ptr, nbytes))) {
        err_sys("read error");
    }

    return (n);
}


void
Write(int fd, void *ptr, size_t nbytes) {
    if (write(fd, ptr, nbytes) != nbytes) {
        err_sys("write error");
    }
}
