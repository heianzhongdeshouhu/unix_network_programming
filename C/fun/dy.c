#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int dy(int *piarray, size_t num_items, size_t *pstart, size_t *pend) {
    assert(piarray && pstart && pend);
    *pstart = 0;
    *pend = 0;
    
    return 0;
}

int main(int argc, char *argv[]) {
    int iarray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    size_t istart, iend;
    dy(iarray, sizeof(iarray)/ sizeof(iarray[0]), &istart, &iend);

    printf("%d\t%d\n", istart, iend);

    exit(0);
}
