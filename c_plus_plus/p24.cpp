#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    char ca[1024] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char ca_0[1024] = {'h', 'e', 'l', 'l', 'o', 'x', '\0'};
    char * const ptr1 = ca;

    //ptr1 = ca_0;
    *ptr1 = 'x';

    printf("%s\n", ptr1);

    exit(0);
}
