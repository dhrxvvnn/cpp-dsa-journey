using namespace std;

#include <vector>

class Solution {
public:
    bool isvalid(int r, int c, int m, int n) {
        if (r<0 || r >=m || c<0 || c>=n) return false;
        return true;
    }

    int dfs(vector<vector<int>>& mat, int m, int n, int r, int c, int& isans) {
        int ans = 1;
        mat[r][c] = -1;

        if (r == 0 || r == m-1 || c == 0 || c == n-1) isans = 0;

        int rdir[] = {-1,0,1,0};
        int cdir[] = {0,1,0,-1};

        for (int i=0; i<4; i++) {
            int nr = r + rdir[i];
            int nc = c + cdir[i];

            if (isvalid(nr, nc, m, n) && mat[nr][nc] == 1) ans += dfs(mat, m, n, nr, nc, isans);
        }

        return ans;
    }

    int numEnclaves(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 1) {
                    int isans = 1;
                    int area = dfs(mat, m, n, i, j, isans);
                    if (isans) ans += area;
                }
            }
        }

        return ans;
    }
};