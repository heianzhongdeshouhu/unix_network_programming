#include <iostream>
using namespace std;
#include <stddef.h>

struct s1{
    char ch;
    int a;
    double b;
    char c1;
};

struct s2{
    char ch;
    int a;
    double b;
};

int main()
{
    cout << "s1的大小： " << sizeof(struct s1) << endl;
    cout << "ch的地址偏移是   " << offsetof(s1, ch) << endl;
    cout << "a 的地址偏移是   " << offsetof(s1, a) << endl;
    cout << "b 的地址偏移是   " << offsetof(s1, b) << endl;
    cout << "c1的地址偏移是   " << offsetof(s1, c1) << endl;

    cout << "=====================================" << endl;
    cout << "s2的大小: " << sizeof(struct s2) << endl;
    cout << "ch的地址偏移是   " << offsetof(s2, ch) << endl;
    cout << "a 的地址偏移是   " << offsetof(s2, a) << endl;
    cout << "b 的地址偏移是   " << offsetof(s2, b) << endl;
    getchar();

    return 0;
}
