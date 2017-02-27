#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// C  c

int fun(const char *pstr, const char c)
{
    assert(pstr);
    assert( ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) );

    char cupper = 0;
    char cdown = 0;
    if ((c >= 'A') && (c <= 'Z')) {
        cupper = c;
        cdown = c + 'a' - 'A';
    } else {
        cupper = c - ('a' - 'A');
        cdown = c;
    }

    int icount = 0;
    size_t offset = 0;
    for ( ; '\0' != pstr[offset]; offset++) {
        if ((pstr[offset] == cupper) || (pstr[offset] == cdown) ) {
            icount++;
        }
    }
    printf("%d\n", icount);

    return 0;
}

int main()
{
#if 0
    char cval = 'C';
    char cval_0 = 'c';
    if (cval_0 > cval) {
        printf("ddddddd");
    }
#endif

    //fun("asA", 'a');
    const char *pstr = "nhrwlbcc8m7c5hih9mhalw98k0322wf2jjm47kk3ntm9snfrflzzundn7d608usy049asxalzjk7izj6amcqhr8uubc04g52mcjboj2fmge2l6iarizfu4yve5o4i3srf5zgqbg82ckcotdeqp760mc9gzei5dzk5gj9x9yj05o3hle0ii64krkkp5i7blh7nbu3gu5vgi2scyn4yqx3z4vcjbyzhnqkh887izotjkg2l0mit0k14vyn39";
    fun(pstr, 't');
    
    exit(0);
}
