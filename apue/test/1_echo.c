#include <stdlib.h>

#include <stdio.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {

    
    char buff[BUFLEN];
    while(fgets(buff, BUFLEN, stdin)) {
        fputs(buff, stdout);
    }

}
