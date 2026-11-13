using namespace std;

#include <vector>

class Solution {
public:
    void dfs(vector<vector<char>>& mat, int m, int n, int i, int j, vector<vector<int>>& vis) {
        if (i<0 || i>=m || j<0 || j>=n) return;
        if (mat[i][j] == '0') return;
        if (vis[i][j]) return;

        vis[i][j] = 1;

        dfs(mat, m, n, i+1, j, vis);
        dfs(mat, m, n, i-1, j, vis);
        dfs(mat, m, n, i, j+1, vis);
        dfs(mat, m, n, i, j-1, vis);

        return;
    }

    int numIslands(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(mat, m, n, i, j, vis);
                }
            }
        }

        return ans;
    }
};