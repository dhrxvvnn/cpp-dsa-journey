#include <iostream>
using namespace std;

#include <vector>
#include <stack>

vector<int> canSeePersonsCount(vector<int>& nums) {
    int n = nums.size();
    stack<pair<int, int>> st;

    vector<int> ans(n, 0);
    for (int i=0; i<n; i++) {
        while (!st.empty() && st.top().first < nums[i]) {
            ans[st.top().second]++;
            st.pop();
        }

        if (!st.empty()) {
            ans[st.top().second]++;
            if (st.top().first != nums[i]) st.push({nums[i], i});
        } else {
            st.push({nums[i], i});
        }
    }

    return ans;
}