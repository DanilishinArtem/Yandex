#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

void AddSynonims(map<string, set<string>>& synonims, const string& first_word, const string& second_word){
    synonims[second_word].insert(first_word);
    synonims[first_word].insert(first_word);
}

int GetSynonimCount(map<string, set<string>>& synonims, const string& word){
    return synonims[word].size();
}

bool CheckSynonim(map<string, set<string>>& synonims, const string& first_word, const string& second_word){
    return synonims[first_word].count(second_word) == 1;
}

int main(){
    int q;
    cin >> q;
    map<string, set<string>> synonims;

    for(size_t i = 0; i < q; i++){
        string operation_code;
        cin >> operation_code;
        if(operation_code == "ADD"){
            string first_word, second_word;
            cin >> first_word, second_word;
            AddSynonims(synonims, first_word, second_word);
        }else if(operation_code == "COUNT"){
            string word;
            cin >> word;
            cout << GetSynonimCount(synonims, word) << endl;
        }else if( operation_code == "CHECK"){
            string first_word, second_word;
            cin >> first_word >> second_word;
            if(CheckSynonim(synonims, first_word, second_word)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}