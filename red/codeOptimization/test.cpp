#include <iostream>
#include <vector>
#include <fstream>
#include "lib.h"
using namespace std;

int main(){
    ofstream out("output.txt");
    for(size_t i = 0; i < 25; i++){
        out << "London is the capital of Great Britain. "
            << "I am travelling douwn the river"
            << "\n";
    }
}