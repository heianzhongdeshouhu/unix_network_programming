#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char *argv[]) {
    int     pipefd[2];
    pid_t   cpid;
    char    buf;
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (-1 == pipe(pipefd)) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (-1 == cpid) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (0 == cpid) {    /* Child reads from pipe */
        printf("child ......\n");

        close(pipefd[1]);       /* Close unused write end */

        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, 1);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    
    } else {            /* Parent writes argv[1] to pipe */
        printf("parent ......\n");

        close(pipefd[0]);   /* Close unused read end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);   /* Reader will see EOF */
        wait(NULL);
        exit(EXIT_SUCCESS);
    
    }
}
