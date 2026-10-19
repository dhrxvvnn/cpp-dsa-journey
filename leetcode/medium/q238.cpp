#include <iostream>
using namespace std;

#include <vector>

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    int z = 0;
    int zidx = -1;
    long prod = 1;
    for (int i=0; i<n; i++) {
        if (nums[i] == 0) {
            z++;
            zidx = i;
        } else prod *= nums[i];
    }

    vector<int> ans(n, 0);

    if (z >= 2) {
        return ans;
    }

    if (z == 1) {
        ans[zidx] = prod;
        return ans;
    }

    for (int i=0; i<n; i++) {
        prod /= nums[i];
        ans[i] = prod;
        prod *= nums[i];
    }

    return ans;
}