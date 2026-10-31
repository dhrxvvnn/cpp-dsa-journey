using namespace std;

#include <vector>

class Solution {
    const int MOD = 1e9 + 7;
public:
    long long solve(vector<vector<int>>& grid, int m, int n, int i, int j, int dir, vector<vector<long long>>& dp) {
        if (i<0 || j<0|| i>= m || j>= n) return 0;

        if (i == m-1 && j == n-1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (grid[i][j] == 0) {
            long long ans = solve(grid, m, n, i+1, j, 1, dp) + solve(grid, m, n, i, j+1, 0, dp);
            return dp[i][j] = ans%MOD;
        }

        if (dir == 0) {
            return (solve(grid, m, n, i+1, j, 1, dp));
        }

        return (solve(grid, m, n, i, j+1, 0, dp));
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>>dp(m, vector<long long>(n, -1));
        return (solve(grid, m, n, 0, 0, 0, dp))%MOD;
    }
};