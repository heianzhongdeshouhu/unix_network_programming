#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {

    
    char buff[BUFLEN];
    while(fgets(buff, BUFLEN, stdin)) {
        //fputs(buff, stdout);
        system(buff);

        size_t len = strlen(buff);
        if ('\n' == buff[len - 1]) {
            printf("the last character is \\n");
        }
    }

}
