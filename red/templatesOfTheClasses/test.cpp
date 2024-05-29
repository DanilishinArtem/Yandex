#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct PairOfStringAndInt{
    string first;
    int second;
};

struct PairOfBoolAndChar{
    bool first;
    char second;
};

template<typename T, typename U>
struct Pair{
    T first;
    U second;
};

int main(){
    Pair<string, int> si;
    si.first = "Hello";
    si.second = 5;

    Pair<bool, char> bc;
    bc.first = true;
    bc.second = 'a';
    return 0;
}