/*
 * Counting sort assumes that each of the n input elements is an integer in the range 0 to k, for some integer k. When k = O(n), the sort runs in ......
 *
 * please refer to the page in page 194.
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

/*
 * @param[in,output] parray : the array to be sorted.
 * @param{in} inum          : the number of the elements in parray.
 */
int counting_sort(int *parray, int inum) {
    int imax = 0;
    for (int i = 0; i < inum; i++) {
        if (parray[i] > imax) {
            imax = parray[i];
        }
    }

    int *pb = calloc(imax + 1, sizeof(int));
    int *pc = calloc(inum, sizeof(int));

    memset(pb, 0, (imax+1) * sizeof(int));
    memset(pc, 0, inum * sizeof(int));

    for (int i = 0; i < inum; i++) {
        pb[parray[i]] += 1;        
    }

    for (int i = 1; i <= imax; i++) {
        pb[i] += pb[i - 1];
    }

    for (int i = inum - 1; i >= 0; i--) {
        pc[pb[parray[i]] - 1] = parray[i];
        pb[parray[i]] -= 1;
    }   

    memcpy(parray, pc, inum * sizeof(int));
    

    free(pc);
    free(pb);    

    return 0;
}

int main(int argc, char *argv[]) {
    //int iarray[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int iarray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t unum = sizeof(iarray)/ sizeof(iarray[0]);
    counting_sort(iarray, unum);

    for (size_t i = 0; i < unum; i++) {
        printf("%d\t", iarray[i]);
    }
    printf("\n");

    exit(0);
}
