#include <iostream>
using namespace std;

#define k 50
void fun(char);

int main(int argc, char *argv[]) {
    fun(k);

    exit(0);
}

void fun(char C) { cout<< "c = "<< C<< endl;}
