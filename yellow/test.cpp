#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cassert>
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

void TestAddSynonims(){
    {
        Synonims empty;
        AddSynonims(empty, "a", "b");
        const Synonims expected = {
            {"a", {"b"}},
            {"b", {"a"}},
        };
        assert(empty == expected);
    }
    {
        Synonims synonims = {
            {"a" , {"b"}},
            {"b" , {"a", "c"}},
            {"c" , {"b"}},
        };
        AddSynonims(synonims, "a", "c");
        const Synonims expected = {
            {"a" , {"b", "c"}},
            {"b" , {"a", "c"}},
            {"c" , {"b", "a"}},
        };
        assert(synonims == expected);
    }
    cout << "Test AddSynonims is passed" << endl;
}

void TestSynonimsCount(){
    {
        Synonims empty;
        assert(GetSynonimCount(empty, "a") == 0);
    }
    {
        Synonims synonims = {
            {"a" , {"b", "c"}},
            {"b" , {"a"}},
            {"c" , {"a"}},
        };
        assert(GetSynonimCount(synonims, "a") == 2);
        assert(GetSynonimCount(synonims, "b") == 1);
        assert(GetSynonimCount(synonims, "z") == 0);
    }
    cout << "Test Synonims count is passed" << endl;
}

void TestCheckSynonim(){
    {
        Synonims empty;
        assert(CheckSynonim(empty, "a", "b") == false);
    }
    {
        Synonims synonims = {
            {"a" , {"b", "c"}},
            {"b" , {"a"}},
            {"c" , {"a"}},
        };
        assert(CheckSynonim(synonims, "a", "b") == true);
        assert(CheckSynonim(synonims, "b", "a") == true);
        assert(CheckSynonim(synonims, "a", "c") == true);
        assert(CheckSynonim(synonims, "c", "a") == true);
        assert(CheckSynonim(synonims, "b", "c") == false);
    }
    cout << "Test CheckSynonims is passed" << endl;
}

void TestProgramm(){
    TestSynonimsCount();
    TestCheckSynonim();
    TestAddSynonims();
}

int main(){
    TestProgramm();
    return 0;
}