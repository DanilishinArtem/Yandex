#include <iostream>
using namespace std;

int main(){
    int x = 5;
    int* px = &x;
    const int* cpx = &x;
    int* const pxc = &x;
    const int* const cpxc = &x;

    // testing of px:
    *px = 1;
    px++;
    // testing of cpx:
    // *cpx = 1; // error (changing const value)
    cpx++;
    // testing of pxc:
    *pxc = 1;
    // pxc++; // error (changing const pointer)
    // testing of cpxc:
    // *cpxc = 1; // error (changing const value)
    // cpxc++; // error (changing const pointer)
    return 0;
}