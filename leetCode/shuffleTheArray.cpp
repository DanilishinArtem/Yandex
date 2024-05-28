#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    for(size_t i = 1; i <= n; i++){
        nums[i - 1] += (2 * (i - 1) + 1) * 10000;
        nums[n + i - 1] += 2 * i * 10000;
    }

    sort(begin(nums), end(nums));
    for(size_t i = 0; i < 2 * n; i++){
        nums[i] -= (i + 1) * 10000;
    }
    return nums;
}

int main(){
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    shuffle(nums, n);
    for(auto item : nums){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}