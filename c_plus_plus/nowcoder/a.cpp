#include <iostream>
using namespace std;

class Base {
public:
    void fun1() {cout<< "Base\n";}
    virtual void fun2() {cout<< "Base\n";}
};

class Derived: public Base {
    public:
    void fun1() {cout<< "Derived\n";}
    void fun2() {cout<< "Derived\n";}
};

void f(Base &b) {
    b.fun1();
    b.fun2();
}

int main(int argc, char *argv[]) {
    Derived obj;
    f(obj);
    
    exit(0);
}
