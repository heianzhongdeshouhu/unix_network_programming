/*
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int fun(const float fval, int *presult) {
    assert(presult);

    int itemp = fval;
    float ftemp = fval - itemp;
    ftemp *= 10;
    if (ftemp >= 5) {
        *presult = itemp + 1;
    } else {
        *presult = itemp;
    }

    
    return 0;
}

int main(int argc, char *argv[]) {
    int iresult;
    //float fval = 4.4;
    float fval = 4.7;
    fun(fval, &iresult);

    printf("%d\n", iresult);


    exit(0);
}
*/

//#include <iostream>
//using namespace std;

#include <stdio.h>
int main()
{
    /*
    float a;
    while(cin>>a)
    {
        if(a>0)
            cout<<int(a+0.5)<<endl;
    }
    */
    
    double a = ((double)1)/3;

    double b = 0.333333;
    printf("a=%f,b=%f\n", a,b);

    if(a ==b)
        printf("===========\n");
    else
        printf("!=\n");
    return 0;
}
