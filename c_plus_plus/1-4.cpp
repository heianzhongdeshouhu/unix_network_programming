#include <iostream>
using namespace std;

void t(int &);

int main(int argc, char *argv[]) {
    int i = 0;
    t(i);

    cout<< "i = "<< i<< endl;

    exit(0);
}

void t(int &ip) {cout<< "ip = "<< ip<< endl; ip++;}
