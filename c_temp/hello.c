#include <stdlib.h>
#include <stdio.h>

void f(char **p) {
    printf("sizeof(*p) = %u\n", sizeof(*p));

    *p += 2;
}

int main(int argc, char *argv[]) {
    char *a[] = {"123", "abc", "456"}, **p;
    p = a;
    f(p);
    printf("%s\n", *p);

    exit(0);
}
