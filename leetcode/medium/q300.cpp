using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> scores(n, -1);
        for (int i=n-1; i>=0; i--) {
            int lis = 1;
            for (int j=i+1; j<n; j++) {
                if (nums[j] > nums[i]) lis = max(lis, 1 + scores[j]);
            }
            scores[i] = lis;
        }

        return *max_element(scores.begin(), scores.end());
    }
};