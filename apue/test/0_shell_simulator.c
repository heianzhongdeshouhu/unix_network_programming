#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include <stdio.h>

#define BUFLEN 1024

int syslog(const char *pmsg) {
    printf("%s\n", pmsg);
    return 0;
}

int get_input__output_result() {
    printf("[wolf in child]");

    char buff[BUFLEN];
    while(fgets(buff, BUFLEN, stdin)) {
        size_t len = strlen(buff);
        if ('\n' == buff[len - 1]) {
            buff[len - 1] = '\0';
        }

        if (0 == strcmp("exit", buff)) {
            printf("welcome back, ^_^\n");
            break;
        } else {
            system(buff);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    syslog("wolf");

    pid_t pid = fork();
    if (0 == pid) {         // child process
        get_input__output_result();
    } else if (0 < pid) {   // parent process

        int ival = waitpid(pid, NULL,0);
        if (-1 == ival) {
            syslog("waitpid() error");
        }

    } else {                // fork error
        syslog("fork() error");
    }

    exit(0);
}
