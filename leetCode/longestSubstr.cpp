#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool CheckSubstr(const string& sub, const set<char>& letters){
        set<char> letters2;
        for(const char& item : sub){
            letters2.insert(item);

        }
        if(letters2.size() != sub.size()){
            return false;
        }else{
            return true;
        }
    }
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        int result = 0;
        set<char> letters;
        for(const char& item : s){
            letters.insert(item);
        }
        size = letters.size();

        for(size_t i = size; i > 0; i--){
            for(size_t j = 0; j < s.size() - i + 1; j++){
                string sub = s.substr(j, i);
                if(CheckSubstr(sub, letters)){
                    result = sub.size();
                    return result;
                }
            }
        }
        return result;
    }
};


int main(){
    Solution s;
    string s1 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(s1) << endl;
    string s2 = "bbbbb";
    cout << s.lengthOfLongestSubstring(s2) << endl;
    string s3 = "pwwkew";
    cout << s.lengthOfLongestSubstring(s3) << endl;
    return 0;
}