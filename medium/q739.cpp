#include <iostream>
using namespace std;

#include <vector>
#include <stack>

vector<int> dailyTemperatures(vector<int>& nums) {
    stack<int> st;

    vector<int> ans(nums.size());
    for (int i=0; i<nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            ans[st.top()] = i - st.top();

            st.pop();
        }

        st.push(i);
    }

    while (!st.empty()) {
        ans[st.top()] = 0;
        st.pop();
    }

    return ans;
}