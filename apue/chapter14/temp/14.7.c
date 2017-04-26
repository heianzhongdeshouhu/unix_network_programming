#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

#include "lock_common.h"

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

static void
lockabyte(const char *name, int fd, off_t offset) {
    if (writew_lock(fd, offset, SEEK_SET, 1) < 0) {
        printf("%s: writew_lock error", name);
    }
    printf("%s: got the lock, byte %lld\n", name, (long long)offset);
}

void
TELL_WAIT(void);

void
TELL_PARENT(pid_t pid);

void
WAIT_PARENT(void);

void
TELL_CHILD(pid_t pid);

void
WAIT_CHILD(void);

int 
main(int argc, char *argv[]) {

    int     fd;
    pid_t   pid;

    /*
     * Create a file and write two bytes to it.
     */
    if ((fd = creat("templock", FILE_MODE)) < 0) {
        printf("create error");
    }
    if (write(fd, "ab", 2) != 2) {
        printf("write error");
    }

    TELL_WAIT();
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (0 == pid) {       /* child */
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    } else {                    /* parent */
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte("parent", fd, 0);
    }

    exit(0);
}

/**/
static int pfd1[2], pfd2[2];

void
TELL_WAIT(void) {
    if (pipe(pfd1) < 0 || pipe(pfd2) < 0) {
        printf("pipe error");
    }
}

void
TELL_PARENT(pid_t pid) {
    if (1 != write(pfd2[1], "c", 1)) {
        printf("write error");
    }
}

void
WAIT_PARENT(void) {
    char    c;

    if (1 != read(pfd1[0], &c, 1)) {
        printf("read error");
    }

    if ('p' != c) {
        printf("WAIT_PARENT: incorrect data");
    }
}

void
TELL_CHILD(pid_t pid) {
    if (1 != write(pfd1[1], "p", 1)) {
        printf("write error");
    }
}

void 
WAIT_CHILD(void) {
    char    c;

    if (1 != read(pfd2[0], &c, 1)) {
        printf("read error");
    }

    if ('c' != c) {
        printf("WAIT_CHILD: incorrect data");
    }
}
