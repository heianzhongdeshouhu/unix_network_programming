#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
/*
typedef struct heap_node{
    int ikey;
    struct heap_node *pleft;
    struct heap_node *pright;
}hn;
*/

/*
 * swap the value of *pval_0 and *pval_1.
 */
int swap_value(int *pval_0, int *pval_1) {
    assert(pval_0 && pval_1);

    int itemp = *pval_0;
    *pval_0 = *pval_1;
    *pval_1 = itemp;
    
    return 0;
}

/*
 * @param[in, output]   pheap       :   pointer to the heap.
 * @param[in]           num_pheap   :   the number of the elements in the heap: pheap
 * @param[in]           i           :   the index of the node in the heap.
 */
int max_heapify(int *pheap, int num_heap, int i) {
    assert(pheap && (i >= 0));

    int ileft = 2 * i + 1;
    int iright = 2 * i + 2;
    int imax = i;
    if (ileft < num_heap) {
        if (pheap[i] < pheap[ileft]) {
            imax = ileft;
        }
    }
    if (iright < num_heap) {
        if (pheap[imax] < pheap[iright]) {
            imax = iright;
        }
    }

    if (imax != i) {
        swap_value(&(pheap[i]), &(pheap[imax]));

        max_heapify(pheap, num_heap, imax);
    }

    return 0;
}

/*
 * @param[in, output] pi    : the input array
 * @param[in] len           : the number of the elements in the array: pi.
 */
int build_max_heap(int *pi, int inum) {
    assert(pi && (inum > 0));

    for (int i = (inum -1)/2; i >= 0 ; i--) {
        max_heapify(pi, inum, i);
    }

    return 0;
}

/*
 * @param[in,output]    piarray : the array to be sorted.
 * @param[in]           inum    : the number of the element in piarray.
 */
int heap_sort(int *piarray, int inum) {
    assert(piarray && (inum > 0));    
    
    build_max_heap(piarray, inum);
    swap_value(&(piarray[0]), &(piarray[inum - 1]));

    for (int i = inum - 1; i > 0; i--) {
        max_heapify(piarray, i, 0);
        swap_value(&(piarray[0]), &(piarray[i - 1]));
    }
    

    return 0;
}

int fun() {
    int iarray[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    
    heap_sort(iarray, sizeof(iarray)/ sizeof(iarray[0]));

    for (int i = 0, inum = sizeof(iarray)/ sizeof(iarray[0]); i < inum; i++) {
        printf("%d\t", iarray[i]);
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[]) {
    fun(); 
    
    exit(0);
}
