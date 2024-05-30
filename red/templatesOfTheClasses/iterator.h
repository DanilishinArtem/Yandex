#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for(const T& item : v){
        out << item << ' ';
    }
    return out;
}

template<typename Iterator>
struct IteratorRange{
    Iterator first, last;

    Iterator begin() const{
        return first;
    }
    Iterator end() const{
        return last;
    }
};

template<typename T>
IteratorRange<typename vector<T>::iterator> Head2(vector<T>& v, int n){
    // for creation of the class IteratorRange we whould use:
    // IteratorRange<typename vector<T>::iterator> iterator;
    n = min(n, static_cast<int>(v.size()));
    return {v.begin(), v.begin() + n};
};