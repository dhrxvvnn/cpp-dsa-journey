#include <iostream>
using namespace std;

#include <vector>

int candy(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    for (int i=1; i<nums.size(); i++) {
        if (nums[i] > nums[i-1]) ans[i] = ans[i-1] + 1;
    }

    for (int i=nums.size()-2; i>=0; i--) {
        if (nums[i] > nums[i+1]) ans[i] = max(ans[i], ans[i+1] + 1);
    }

    return accumulate(ans.begin(), ans.end(), 0);
}