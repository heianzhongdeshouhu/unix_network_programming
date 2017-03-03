#include <stdlib.h>
#include <stdio.h>

int fun(int inum, int *presult, int *presult_len) {
    int itemp = 0;
    int i = 0;

    for (i = 2; i <= inum; i++) {
        itemp = inum / i;
        if (itemp * i == inum) {
            break;
        }
    }

    int offset = *presult_len;
    *(presult + offset) = i;
    (*presult_len)++;


    if (itemp != 1) {
        fun(itemp, presult , presult_len);
    } 

    return 0;
}

int main() {
    int iprime[100] = {0};
    int iprime_number = 0;
    //int inum = 180;
    //int inum = 10;
    int inum = 14;
    fun(inum, iprime, &iprime_number);

    for (int i = 0; i < iprime_number; i++) {
        printf("%d\t", iprime[i]);
    }
    printf("\n");

    return 0;
}

