using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool iscycle(int i, unordered_map<int, vector<int>>& neighs, vector<bool>& vis, vector<bool>& recpath) {
        vis[i] = true;
        recpath[i] = true;

        for (auto neigh : neighs[i]) {
            if (!vis[neigh]) {
                if (iscycle(neigh, neighs, vis, recpath)) return true;
            } else {
                if (recpath[neigh]) return true;
            }
        }

        recpath[i] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& mat) {
        vector<bool> vis(n, false);

        vector<bool> recpath(n ,false);

        unordered_map<int, vector<int>> neighs;

        for (int i=0; i<mat.size(); i++) {
            neighs[mat[i][1]].push_back(mat[i][0]);
        }

        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                if (iscycle(i, neighs, vis, recpath)) return false;
            }
        }

        return true;
    }
};