#include <stdlib.h>
#include <stdio.h>

class Base {
    public:
        Base() {fun();};
        virtual int fun() {
            printf("Base::fun()");
            return 0;
        }
};

class Derived: public Base {
    public:
        Derived() {fun();}

        virtual int fun() {
            printf("Derived::fun() \n");
        }
};


int main(int argc, char *argv[]) {
    Base *pBase = new Derived;
    pBase->fun();

    delete pBase;

    exit(0);
}
