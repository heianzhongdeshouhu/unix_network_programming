#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int 
main(int argc, char  *argv[]) {
    int         i;
    char        **ptr;
    extern char **envron;
    
    for (i = 0; i < argc; i++) {    /* echo all command-line args */
        printf("argv[%d]: %s\n", i, argv[i]);
    }

#if 0
    for (ptr = environ; *ptr != 0; ptr++) { /* and all env strings */
        printf("%s\n", *ptr);
    }
#endif

    exit(0);
}
