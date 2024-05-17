#include <string>
#include <map>
#include <set>
using namespace std;

using Synonims = map<string, set<string>>; 

void AddSynonims(Synonims& synonims, const string& first_word, const string& second_word);

int GetSynonimCount(Synonims& synonims, const string& word);

bool CheckSynonim(Synonims& synonims, const string& first_word, const string& second_word);