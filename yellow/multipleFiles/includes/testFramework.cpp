// #include "testFramework.h"


void SetColor(int color){
    cerr << "\033[" << color << "m";
}

template<typename Func>
void TestRunner::RunTest(Func func, const string& nameOfFunction){
    try{
        func();
        SetColor(32);
        cerr << "Test " << nameOfFunction << " is passed" << endl;
    }catch(runtime_error& e){
        fail_counter ++;
        SetColor(31);
        cerr << "Test " << nameOfFunction << " is failed: " << e.what() << endl;
    }
}

TestRunner::~TestRunner(){
    if(fail_counter > 0){
        SetColor(31);
        cerr << "Total number of failed tests: " << fail_counter << endl;
        exit(1);
    }else{
        SetColor(32);
        cerr << "All tests are passed" << endl;
    }
}

template <typename K>
ostream&  operator << (ostream& os, const set<K>& s){
    os << "{";
    bool first = true;
    for(const auto& item : s){
        if(!first){
            os << ", ";
        }
        first = false;
        os << item;
    }
    return os << "}";
}

template <typename K, typename V>
ostream& operator << (ostream& os, const map<K, V>& m){
    os << "{";
    bool first = true;
    for(const auto& item : m){
        if(!first){
            os << ", ";
        }
        first = false;
        os << item.first << ": " << item.second;
    }
    return os << "}";
}

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint){
    if (t != u){
        stringstream ss;
        ss << "AssertEqual failed: " << t << " != " << u << ", hint: " << hint;
        throw runtime_error(ss.str());
    }
}