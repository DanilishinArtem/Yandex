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
class IteratorRange{
private:
    Iterator first, last;
public:
    IteratorRange(Iterator first, Iterator last) : first(first), last(last){}
    Iterator begin() const{
        return first;
    }
    Iterator end() const{
        return last;
    }
};

template<typename Container>
// IteratorRange<typename Container::iterator> Head(Container& v, int n){
auto Head(Container& v, int n){
    n = min(n, static_cast<int>(v.size()));
    return IteratorRange{v.begin(), next(v.begin(), n)};
};