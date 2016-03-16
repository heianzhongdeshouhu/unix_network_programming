#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int err_sys(const char *pmsg);
void pr_exit(int status) {
        if (WIFEXITED(status)) {
                printf("normal termination, exit status = %d\n",
                                WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
                printf("abnormal termination, signal number = %d%s\n",
                                WTERMSIG(status),
#ifdef WCOREDUMP
                                WCOREDUMP(status) ? " (core file generated)": "");
#else
                "" );
#endif
        } else if (WIFSTOPPED(status)) {
                printf("child stopped, signal number = %d\n",
                                WSTOPSIG(status));
        }
}

int
main(int argc, char *argv[]) {
        pid_t   pid;
        int     status;

        if ((pid = fork()) < 00) {
                err_sys("fork error");
        } else if (pid == 0) {       /* child */
                exit(7);
        }

        if (wait(&status) != pid){  /* wait for child */ 
                err_sys("wait error");
        }
        pr_exit(status);            /* and print its status*/
        
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {      /* child */
            abort();                /* generate SIGABRT */
        }        

        if (wait(&status) != pid) { /* wait for child */
            err_sys("wait error");
        }
        pr_exit(status);            /* and prints its status */

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {      /* child */
            status /= 0;            /* divide by zero generates SIGFPE*/
        }

        if (wait(&status) != pid) { /* wait for child */
            err_sys("wait error");
        }
        pr_exit(status);            /* and prints its status */

        exit(0);
}

int err_sys(const char *pmsg) {
        if (pmsg) {
                printf("%s\n", pmsg);
        }
        return 0;
}

