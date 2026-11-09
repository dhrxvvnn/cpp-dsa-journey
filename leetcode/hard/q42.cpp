using namespace std;

#include <vector>
#include <stack>

int trap(vector<int>& nums) {
    int n = nums.size();

    vector<int> nxthighest(n, -1);
    vector<int> prevhighest(n, -1);

    stack<int> st;
    for (int i=n-1; i>=0; i--) {
        int h = nums[i];

        while (!st.empty() && nums[st.top()] < h) st.pop();

        if (st.empty()) nxthighest[i] = -1;
        else nxthighest[i] = st.top();

        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i=0; i<n; i++) {
        int h = nums[i];

        while (!st.empty() && nums[st.top()] < h) st.pop();

        if (st.empty()) prevhighest[i] = -1;
        else prevhighest[i] = st.top();

        st.push(i);
    }

    int ans = 0;

    int left = 0;
    while (left < n && nums[left] == 0) left++;

    if (left == n) return 0;

    while (true) {
        int right = nxthighest[left];
        if (right == -1) break;

        ans += nums[left] * (right-left-1);

        left++;
        while (left < right) {
            ans -= nums[left];
            left++;
        }
    }

    if (left == n-1) return ans;

    int right = n-1;
    while (right >= 0 && nums[right] == 0) right--;

    if (right <= left) return ans;

    while (true) {
        int l = prevhighest[right];

        ans += nums[right] * (right - l - 1);

        right--;
        while (right > l) {
            ans -= nums[right];
            right--;
        }

        if (right == left) break;
    }
    
    return ans;
}