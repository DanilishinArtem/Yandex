#include <string>
#include <map>
#include <set>
using namespace std;

using Synonims = map<string, set<string>>; 

void AddSynonims(Synonims& synonims, const string& first_word, const string& second_word){
    synonims[second_word].insert(first_word);
    // synonims[first_word].insert(first_word); // that is not right
    synonims[first_word].insert(second_word); // that is right
}

int GetSynonimCount(Synonims& synonims, const string& word){
    return synonims[word].size();
}

bool CheckSynonim(Synonims& synonims, const string& first_word, const string& second_word){
    return synonims[first_word].count(second_word) == 1;
}
