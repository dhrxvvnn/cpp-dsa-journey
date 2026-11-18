using namespace std;

#include <vector>

class Solution {
public:
    int solve(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low)/2;

        int ans = 0;
        ans += solve(nums, low, mid);
        ans += solve(nums, mid+1, high);

        int j = low;
        for (int i=mid+1; i<=high; i++) {
            while (j <= mid && nums[j] <= 2LL*nums[i]) j++;
            if (j == mid+1) break;

            ans += mid-j+1; 
        }

        vector<int> tmp;

        int i=low; 
        j=mid+1;
        while(i<=mid && j<=high) {
            if (nums[i] < nums[j]) tmp.push_back(nums[i++]);
            else tmp.push_back(nums[j++]);
        }

        while (i<=mid) tmp.push_back(nums[i++]);
        while (j<=high) tmp.push_back(nums[j++]);

        for (int i=0; i<high-low+1; i++) {
            nums[low+i] = tmp[i];
        }

        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};