#include <iostream>
using namespace std;

class Demo {
private:
    char *s;
    public:
    Demo() { s = new char[1024]; }
    ~Demo() { delete []s; }
};
int main(int argc, char *argv[]) {
    Demo h;

    exit(0);
}
