#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//char *returnStr()
//{
//    char *p = "hello world";
//    return p;
//}

//char *returnStr()
//{
//    char p[] = "hello world";
//    return p;
//}

//char *returnStr()
//{
//    static char p[] = "hello world";
//    return p;
//}

//char *GetMemory3(int num) {
//    char *p = (char *)malloc(sizeof(char) *num);
//
//    return p;
//}

char *Cstr(void) {

    char a[10] = "like";
    return a;
}

int main(int argc, char *argv[]) {

    //char *str;
    //str = returnStr();
    //printf("%s\n", str);

    //char *str = NULL;
    //str = GetMemory3(100);
    //strcpy(str, "hello");
    //printf("%s\n", str);

    //free(str);

    
    // ----
    char *a = Cstr();
    printf("%c\n", *(a + 1));

    exit(0);
}
