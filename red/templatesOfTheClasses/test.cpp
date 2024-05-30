#include "iterator.h"
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "source vector: " << v << endl;
    for(int& item: Head2(v, 3)){
        item = 0;
    }
    cout << "changed vector for Head2 using: " << v << endl;

    IteratorRange<typename vector<int>::iterator> secondHalf = {
        v.begin() + v.size() / 2,
        v.end()
    };
    cout << "secondHalf: " << endl;
    for(int& item : secondHalf){
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}