#include "logDuration.h"
#include <deque>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#pragma once
using namespace std;

void testAddingElements(){
    const int N = 100000;
    {
        LOG_DURATION("vector");
        vector<int> v;
        for(size_t i = 0; i < N; i++){
            v.insert(v.begin(), i);
        }
    }
    {
        LOG_DURATION("deque");
        deque<int> D;
        for(size_t i = 0; i < N; i++){
            D.insert(D.begin(), i);
        }
    }
}

void testLowerBound(){
    const int N = 1000000;
    set<int> numbers;
    for(size_t i = 0; i < N; i++){
        numbers.insert(i);
    }
    const int x = N;

    {
        LOG_DURATION("global_lower_bound");
        cout << *lower_bound(begin(numbers), end(numbers), x) << endl;
    }
    {
        LOG_DURATION("method_lower_bound");
        auto result = numbers.lower_bound(x);
        cout << *result << endl;
    }
}

void testFindIf(){
    const int N = 100000000;
    const int Number = 34545632;
    const int QueryNumber = 1000;
    vector<int> numbers;
    for(size_t i = 0; i < N; i++){
        numbers.push_back(i * 10);
    }
    {
        LOG_DURATION("lower_bound");
        for(size_t i = 0; i < QueryNumber; i++){
            lower_bound(begin(numbers), end(numbers), Number);
        }
    }
    {
        LOG_DURATION("find_if");
        for(size_t i = 0; i < QueryNumber; i++){
            find_if(begin(numbers), end(numbers), [Number](int x){return x >= Number;});
        }
    }
}