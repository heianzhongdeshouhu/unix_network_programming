
/*
 * Bucket sort assume that the input is drawn from a uniform distribution and 
 * has an average-case running time of O(n). 
 * Like counting sort, bucket sort is fast because it assumes something about 
 * the input. Whereas counting sort assumes that the input consists of integers
 * in a small range, bucket sort assumes that the input is generated by a random
 * process that distributes  elements uniformly and independently over the 
 * interval [0,1). (See Section C.2  for a definition of uniform distribution.)
 *
 * please refer to the code in page 201.
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct list_node {
    double key;
    struct list_node *pnext;
}lnode, *plnode;

/*
 * insert a new value to the list corresponding to *pphead, and make sure that the values in the list is sorted from small to large.
 */
int list_insert(lnode **pphead, double dval) {
    assert(pphead);

    lnode *pnew = calloc(1, sizeof(lnode));
    memset(pnew, 0, sizeof(lnode));
    pnew->key = dval;

    if (NULL == *pphead) {

        *pphead = pnew;
        return 0;
    } else {
        lnode *pcurrent = *pphead;
        lnode *prev = NULL;
        while (pcurrent) {
            if (pcurrent->key > dval) {
                break;
            } else {
                prev = pcurrent;
                pcurrent = pcurrent->pnext;
            }
        }

        if (NULL == pcurrent) {
            prev->pnext = pnew;        
        } else {
            if (NULL == prev) { // no items in the list is smaller than dval.
                pnew->pnext = *pphead;
                *pphead = pnew;
            } else {
                prev->pnext = pnew;
                pnew->pnext = pcurrent;
            }
        }
    }
    return 0;
}

int copy_value_from_list(lnode *phead, double **pptr) {
    assert(pptr);
    
    lnode *pcurrent = phead;
    while (pcurrent) {
        *(*pptr) = pcurrent->key;
        (*pptr)++;

        pcurrent = pcurrent->pnext;
    }

    return 0;
}

int list_release(lnode *phead) {
    
    lnode *pcurrent = phead;
    while (pcurrent) {
        lnode *pdel = pcurrent;

        pcurrent = pcurrent->pnext;
        free(pdel);
    }

    return 0;
}

/*
 * with the assumption that the datas are uniformly distributed.
 *
 * @param[in, output] parray    : the array to be sorted.
 * @param[in]   unum            : the number of the elements in parray.
 */
int bucket_sort(double *parray, size_t unum) {
    plnode *pb = calloc(unum, sizeof(plnode)); 

    for (size_t u = 0; u < unum; u++) {
        unsigned long uindex = unum * parray[u];
        list_insert(&(pb[uindex]), parray[u]);
    }


    double *ptr = parray;
    for (size_t u = 0; u < unum; u++) {
        copy_value_from_list(pb[u], &ptr);
    }

    /* release the memory. */
    for (size_t u = 0; u < unum; u++) {
        list_release(pb[u]);
    }
    free(pb);

    return 0;
}

int main(int argc, char *argv[]) {

    double darray[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    size_t unum = sizeof(darray)/ sizeof(darray[0]);


    bucket_sort(darray, unum);

    //
    for (size_t u = 0; u < unum; u++) {
        printf("%f\t", darray[u]);
    }
    printf("\n");


    exit(0);
}
