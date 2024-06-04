#include "iterator.h"
#include <set>
#include <queue>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "source vector: " << v << endl;
    for(int& item: Head(v, 3)){
        item = 0;
    }

    set<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int item : Head(nums, 4)){
        cout << item << ' ';
    }
    cout << endl;

    deque<int> numsd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int item : Head(numsd, 4)){
        cout << item << ' ';
    }
    cout << endl;

    // it will not work, because we use const variable
    const deque<int> const_numsd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int item : Head(const_numsd, 4)){
        cout << item << ' ';
    }
    return 0;
}