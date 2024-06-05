#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "profiler.h"
using namespace std;


void test_function(string filename){
    ifstream in(filename);
    int element_count;
    in >> element_count;
    set<int> elements;
    for(size_t i = 0; i < element_count; i++){
        int x;
        in >> x;
        elements.insert(x);
    }

    int query_count;
    in >> query_count;
    int total_found = 0;
    for(size_t i = 0; i < query_count; i++){
        int x;
        in >> x;
        if (elements.find(x) != elements.end()){
            total_found++;
        }
    }
    cout << total_found << endl;
}


int main(){
    cout << "Example of using custome profiler" << endl;
    {
        LOG_DURATION("test_function");
        test_function("input.txt");
    }
    cout << "Done" << endl;
    return 0;
}