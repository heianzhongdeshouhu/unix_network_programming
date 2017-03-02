#include <iostream>
using namespace std;

class CA {
    public:
        virtual ~CA() { cout<< "CA::~CA() is called ^_^\n";}
        //~CA() { cout<< "CA::~CA() is called ^_^\n";}
};

class CB: public CA {
    public:
        CB(int i) { buf = new char[i];}
        virtual ~CB() {
            delete []buf;
            cout<< "CB::~CB is called ^_^\n";
        }
    private:
        char *buf;
};

void fun(CA *pca) {
    delete pca;
}


int main(int argc, char *argv[]) {
    CA *pa = new CB(15);    
    fun(pa);

    exit(0);
}
