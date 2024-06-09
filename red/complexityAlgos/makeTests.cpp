#include "logDuration.h"
#include "tests.h"
#include <deque>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    cout << "[testing testAddingElements]\n";
    testAddingElements();
    cout << "[testing testLowerBound]\n";
    testLowerBound();
    cout << "[testing testFindIf]\n";
    testFindIf();
    return 0;
}

// ./a.out > result.txt