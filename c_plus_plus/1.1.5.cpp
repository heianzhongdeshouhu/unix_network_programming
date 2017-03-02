#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int i = 0;
    int &j = i, k = 2;
    j++;
    k++;

    cout<< &i<< "->"<< i<< "\n";
    cout<< &j<< "->"<< j<< "\n";
    cout<< &k<< "->"<< k<< "\n";

    exit(0);
}
