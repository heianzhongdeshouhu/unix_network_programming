#include "unp.h"

void
Close(int fd) {
    if (-1 == close(fd)) {
        err_sys("close error");
    }
}

int
Fcntl(int fd, int cmd, int arg) {
    int n;

    if (-1 == (n = fcntl(fd, cmd, arg))) {
        err_sys("fcntl error");
    }

    return (n);
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

pid_t
Fork(void) {
    pid_t   pid;

    if (-1 == (pid = fork())) {
        err_sys("fork error"); 
    }
    return (pid);
}

