using namespace std;

#include <vector>

class Solution {
public:
    void solvef(vector<int>& nums, int target, int l, int r, int& first) {
        if (l > r) return;

        int mid = l + (r - l)/2;

        if (nums[mid] == target) {
            first = mid;
            solvef(nums, target, l, mid-1, first);
            return;
        } 

        if (nums[mid] < target) solvef(nums, target, mid+1, r, first);
        else solvef(nums, target, l, mid-1, first);

        return;
    }

    void solvel(vector<int>& nums, int target, int l, int r, int& last) {
        if (l > r) return;

        int mid = l + (r - l)/2;

        if (nums[mid] == target) {
            last = mid;
            solvel(nums, target, mid+1, r, last);
            return;
        } 

        if (nums[mid] < target) solvel(nums, target, mid+1, r, last);
        else solvel(nums, target, l, mid-1, last);

        return;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        solvef(nums, target, 0, nums.size()-1, first);
        solvel(nums, target, 0, nums.size()-1, last);

        return {first, last};
    }
};