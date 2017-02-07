

static void sig_usr(int);   /* one handler for both signals */

int
main(int argc, char *argv[]) {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSR1");
    }

    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        err_sys("can't catch SIGUSR2");
    }

    for ( ; ; ) {
        pause();
    }
}

static void 
sig_usr(int signo)      /* argument is signal number */
{
    if (signo == SIGUSR1) {
        printf();
    }
}
