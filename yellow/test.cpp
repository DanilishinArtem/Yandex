#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

using namespace std;

ostream&  operator << (ostream& os, const pair<string, int>& s){
    cout << s.first << " " << s.second;
    return os;
}

template <typename T>
void printRange(T begin, T end){
    for(auto item = begin; item != end; item++){
        cout << *item << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    while(!v.empty()){
        v.erase(begin(v));
    }
    cout << "Empty vector size: " << n << endl;

    deque<int> v_deque(n);
    while(!v_deque.empty()){
        v_deque.erase(begin(v_deque));
    }
    cout << "Empty deque size: " << n << endl;
    return 0;
}

// F:\c-plus-plus-modern-development\c-plus-plus-yellow\04_itieratory-alghoritmy-i-kontieiniery\03_ochieried-diek-i-alghoritmy-poiska
// [2]