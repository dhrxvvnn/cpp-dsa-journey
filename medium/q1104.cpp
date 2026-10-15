using namespace std;

#include <vector>

class Solution {
public:
    vector<int> pathInZigZagTree(int x) {
        vector<int> ans;

        while (true) {
            ans.push_back(x);

            if (x == 1) break;

            if (x%2 == 1) x -= 1;
            x /= 2;
        }

        reverse(ans.begin(), ans.end());

        int idx = ans.size()-2;

        int y = 1;
        for (int i=0; i<idx; i++) {
            y *= 2;
        }
        y *= 4;

        while (idx >= 0) {
            y /= 4;

            int dis = ans[idx] - y;
            ans[idx] = 2*y - 1 - dis;

            idx -= 2;
        }

        return ans;
    }
};