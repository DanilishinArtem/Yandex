#include <iostream>
#include <string>

using namespace std;

bool polyndrome(string s){
    for(size_t i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

string longestPalindrome(string s){
    if(s.size() == 1){
        return s;
    }
    for(size_t i = s.size() - 1; i > 0; i--){
        for(size_t j = 0; j < s.size() - i + 1; j++){
            string sub = s.substr(j, i + 1);
            if(polyndrome(sub)){
                return sub;
            }
        }
    }
    return "";
}


int main(){
    string s;
    // s = "bb";
    // s = longestPalindrome(s);
    // cout << s << endl;
    while(true){
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}