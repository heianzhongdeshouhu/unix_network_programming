#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef enum __type {
    _null,
    _left_top,
    _left,
    _top
   
} __type;


int lcs_length(char *pa, size_t len_pa, char *pb, size_t len_pb, char **ppc, __type **ppcb, size_t *plen_pcb) {
    assert(pa && pb);

    size_t lx = len_pb + 1;
    size_t ly = len_pa + 1;
    *ppc = calloc(lx * ly, sizeof(char));
    *ppcb = calloc(lx * ly, sizeof(__type));
    *plen_pcb = lx;
    
    char *pc = *ppc;
    __type *pcb = *ppcb;

    for (size_t i = 0; i < ly; i++) {
        for (size_t j = 0; j < lx; j++) {

            size_t offset = i * lx + j;
            if ((0 == i) || (0 == j)) {
                pc[offset] = 0;
                pcb[offset] = _null;

            } else {
                if (pa[i - 1] == pb[j - 1]) {
                    size_t offset_1 = (i - 1) * lx + (j - 1);
                    pc[offset] = pc[offset_1] + 1;
                    pcb[offset] = _left_top;
                } else {
                    size_t offset_ij_1 = i * lx + (j - 1);
                    size_t offset_i_1j = (i - 1) * lx + j;

                    if (pc[offset_i_1j] >= pc[offset_ij_1]) {
                        pc[offset] = pc[offset_i_1j];
                        pcb[offset] = _top;
                    } else {
                        pc[offset] = pc[offset_ij_1];
                        pcb[offset] = _left;
                    }
                }
            }
        }
    } 

    // debug
    /*
    for (size_t i = 0; i < ly; i++) {
        for (size_t j = 0; j < lx; j++) {

            size_t offset = i * lx + j;
            //if (pc[offset] != 0) {
            printf("%d\t", pc[offset]);
            //printf("%d\n", pc[offset]);
            //}
        }
        printf("\n");
    }
    printf("\n");
    */
    // debug

    return 0;
}

int print_lcs(const __type *pcb, size_t len_pcb, const char *pa, int i, int j) {
    if ((0 == i) || (0 == j)) {
        return 0;
    }

    size_t offset = i * len_pcb + j;
    if (_left_top == pcb[offset]) {
        print_lcs(pcb, len_pcb, pa, i - 1, j - 1);

        printf("%c\t", pa[i - 1]);
    } else {
        if (_top == pcb[offset]) {
            print_lcs(pcb, len_pcb, pa, i - 1, j);
        } else {
            print_lcs(pcb, len_pcb, pa, i, j - 1);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char pX[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char pY[] = {'B', 'D', 'C', 'A', 'B', 'A'};

    //char pX[] = {'A', 'B', 'C'};
    //char pY[] = {'A', 'B', 'C'};

    //char pX[] = {'A', 'B'};
    //char pY[] = {'A', 'B'};

    char *pc = NULL;
    __type *pcb = NULL;
    size_t len_pcb; // the horizontal length of the two-dimension array: pcb
    
    lcs_length(pX, sizeof(pX)/ sizeof(pX[0]), pY, sizeof(pY)/ sizeof(pY[0]),
        &pc, &pcb, &len_pcb);
    print_lcs(pcb, len_pcb, pX, sizeof(pX)/ sizeof(pX[0]), sizeof(pY)/ sizeof(pY[0]));
    printf("\n");

    exit(0);
}
