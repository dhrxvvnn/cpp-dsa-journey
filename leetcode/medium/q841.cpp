using namespace std;

#include <vector>

class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, vector<bool>& vis) {
        vis[i] = true;

        for (int j:mat[i]) {
            if (!vis[j]) dfs(mat, j, vis);
        }

        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<bool> vis(n, false);

        dfs(mat, 0, vis);

        for (int i=0; i<n; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};