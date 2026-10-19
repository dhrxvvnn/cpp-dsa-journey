#include <iostream>
using namespace std;

#include <vector>

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();

    int mx = nums[0];
    vector<int> mxvl;
    for (int i:nums) {
        if (i > mx) mx = i;
        mxvl.push_back(mx);
    }

    int mn = nums[n-1];
    vector<int> mnvl(n);
    for (int i=n-1; i>=0; i--) {
        if (nums[i] < mn) mn = nums[i];
        mnvl[i] = mn;
    }
    
    for (int i=0; i<n; i++) {
        if (mxvl[i] - mnvl[i] <= k) return i;
    }

    return -1;
}