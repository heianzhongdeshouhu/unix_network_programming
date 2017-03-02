#include <stdlib.h>
#include <stdio.h>

//#pragma pack(2)
class BU {
    int number;
    union UBffer {
        char buffer[13];
        int number;
    }ubuf;
    void foo() {}
    typedef char *(*f)(void *);
    enum {hdd, sdd, blueray} disk;
}bu;

int main(int argc, char *argv[]) {
    printf("sizeof(bu) = %u\n", sizeof(bu));    

    exit(0);
}
