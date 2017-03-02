#include <iostream>
using namespace std;

class Demo {
int i;
public:
    Demo(int k) {i = k; cout<< "i = "<< i<< "\n";}
};

int main(int argc, char *argv[]) {
    int i;
    Demo h(110);

    exit(0);
}
