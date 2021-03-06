#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//#define __cut_rod

#define LEN 1024

int max(int ival_0, int ival_1) {
    if (ival_0 > ival_1) {
        return ival_0;
    } else {
        return ival_1;
    }
}

#ifdef __cut_rod
int cut_rod(int *p, int n) {
    if (0 == n) {
        return 0;
    }
    int q = -1;
    for (int i = 0 + 1; i <= n; i++) {
        q = max(q, p[i] + cut_rod(p, n - i));
    }

    return q;
}
#endif

int memorized_cut_rod(int *ptariff, int n, int *poptimal) {
    assert(ptariff && poptimal);
    if (-1 != poptimal[n]) {
        return poptimal[n];
    }
    if (0 == n) {
        poptimal[n] = 0;
        return poptimal[n];
    }

    int q = -1;
    for (int i = 0 + 1; i <= n; i++) {
        q = max(q, ptariff[i] + memorized_cut_rod(ptariff, n - i, poptimal));
    }
    poptimal[n] = q;
    printf("poptimal[%d] = %d\n", n, poptimal[n]);

    return poptimal[n];
}

int main() {
    int itariff[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int n = 10;

#ifdef __cut_rod
    int irevenue = cut_rod(itariff, n);
#else
    int ioptimal[LEN] = {0};
    for (int i = 0; i < LEN; i++) {
        ioptimal[i] = -1;
    }

    int irevenue = memorized_cut_rod(itariff, n, ioptimal);
#endif
    printf("n = %d, reverse = %d\n", n, irevenue);

    exit(0);
}
