#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int err_sys(const char *pmsg);

static void charatatime(char *);

int 
main(int argc, char *argv[]) {
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent"); 
    }

    exit(0);
}

static void charatatime(char *str) {
    char    *ptr;
    int     c;

    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0; ) {
        putc(c, stdout);
    }
}

int err_sys(const char *pmsg) {
    if (pmsg) {
        printf("%s\n", pmsg);
    }
    return 0;
}
