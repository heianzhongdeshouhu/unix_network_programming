#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    struct Dt{unsigned int mm, dd, yy;};
    Dt dt[3];

    for (int i = 0; i < 3; i++) {
        dt[i].mm = 8;
        dt[i].yy= 1994;
        dt[i].dd= i + 15;
        cout<< "mm: yy: dd "<< dt[i].mm<< " "<< dt[i].yy<< " "<< dt[i].dd<< endl;
    }
}
