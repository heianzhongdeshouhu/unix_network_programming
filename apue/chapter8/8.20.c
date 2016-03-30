#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int err_sys(const char *pmsg);

int main(int argc, char *argv[]) {
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (0 == pid) {      /* child */
        if (execl("/home/meng/src/src_meng/src_c/git/up/unix_network_programming/apue/chapter8/testinterp", 
                    "testinterp", "myarg1", "MY ARG2", (char *)0) < 0) {
            int ierror = errno;
            err_sys("execl error");
            printf("    errno = %d, description: %s\n", ierror, strerror(ierror));
        }
    }
    if (waitpid(pid, NULL, 0) < 0) {    /* parent */
        int ierror = errno;
        err_sys("wait error");
        printf("    errno = %d, description: %s\n", ierror, strerror(ierror));
    }

    exit(0);
}

int err_sys(const char *pmsg) {
    if (pmsg) {
        printf("%s\n", pmsg);
    }
    return 0;
}

