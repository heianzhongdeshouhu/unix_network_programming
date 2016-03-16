#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     globvar = 6;        /* external variable in initialized data */

int err_sys(const char *pmsg);
int
main(int argc, char *argv[]) {
    int     var;            /* automatic variable on the stack */
    pid_t   pid;

    var = 88;
    printf("before vfork\n");   /* we don't flush stdio */
    if ((pid = fork()) < 0) {
        err_sys("vfork() error");
    } else if (pid == 0) {       /* child */
        globvar++;              /*modify parent's variables */
        var++;

        _exit(0);               /* child terminates */
    }
    
    /* parent continues here */
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}

int err_sys(const char *pmsg) {
    if (pmsg) {
        printf("%s\n", pmsg);
    }
    return 0;
}
