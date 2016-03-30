#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int err_sys(const char *pmsg);

char    *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int 
main(int argc, char *argv[]) {
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (0 == pid) {      /* specify pathname, specify environment */
        if (execle("/home/meng/echoall", "echoall", "myarg1",
                    "MY ARG2", (char *)0, env_init) < 0) {
            err_sys("execle error");
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        err_sys("wait error");
    }

    if ((pid = fork()) < 0) {
        err_sys("wait error");
    } else if (0 == pid) {      /* specify filename, inherit environment */
//        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0) {
        if (execlp("echoall", "only 1 arg", (char *)0) < 0) {
            err_sys("execlp error");
        }

    }

    exit(0);
}

int err_sys(const char *pmsg) {
    if (pmsg) {
        printf("%s\n", pmsg);
    }
    return 0;
}

