#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct s1 {
    char ch;
    int a;
    double b;
    char c1;
};

struct s2 {
    char ch;
    int a;
    double b;
};
int main(int argc, char *argv[]) {
    printf("sizeof(double) = %u\n", sizeof(double));
    printf("sizeof(s1) = %u\n", sizeof(struct s1));
    printf("offsetof(s1.ch) = %u\n", offsetof(s1, ch));
    printf("offsetof(s1.a) = %u\n", offsetof(s1, a));
    printf("offsetof(s1.b) = %u\n", offsetof(s1, b));
    printf("offsetof(s1.c1) = %u\n", offsetof(s1, c1));

    printf("============================\n");
    printf("sizeof(s2) = %u\n", sizeof(struct s2));
    printf("offsetof(s2.ch) = %u\n", offsetof(s2, ch));
    printf("offsetof(s2.a) = %u\n", offsetof(s2, a));
    printf("offsetof(s2.b) = %u\n", offsetof(s2, b));
    exit(0);
}
