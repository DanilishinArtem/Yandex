#include <iostream>
#include <algorithm>
#include <map>

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
    map<string, int> langs = {
        {"python", 26},
        {"C++", 34},
        {"C", 45},
        {"Java", 22},
        {"C#", 17}
    };

    auto it = langs.find("C++");
    printRange(langs.begin(), it);
    printRange(it, langs.end());
    return 0;
}


// F:\c-plus-plus-modern-development\c-plus-plus-yellow\04_itieratory-alghoritmy-i-kontieiniery\02_ispol-zovaniie-itieratorov-v-alghoritmakh-i-kontieinierakh
// [1]