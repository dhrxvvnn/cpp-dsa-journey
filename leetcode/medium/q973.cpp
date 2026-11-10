using namespace std;

#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size();

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int d = x*x + y*y;

            pq.push({d, i});
        }

        vector<vector<int>> ans;

        while (k--) {
            int i = pq.top().second;
            ans.push_back(points[i]);
            pq.pop();
        }

        return ans;
    }
};