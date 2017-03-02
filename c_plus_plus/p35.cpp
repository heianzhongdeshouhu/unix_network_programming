#include <iostream>
using namespace std;

class CA {
public:
    CA() {cout<< "CA::CA() is called.\n";}
    CA(const CA &other) {cout<< "CA::CA(const CA &other) is called.\n";}
    CA &operator=(const CA &other) {cout<< "CA:: A &operator=(const A &other) is called.\n";}
};

class CB {
    public:
    CB(const CA &a):m_a(a) {}
    //CB(const CA &a) { m_a = a;}
    private:
    CA m_a;
};

int main(int argc, char *argv[]) {
    CA ca;
    printf("// ----------\n\n");
    CB cb(ca);
    printf("\n");

    exit(0);
}
