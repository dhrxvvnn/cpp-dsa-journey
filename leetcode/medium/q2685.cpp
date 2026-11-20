using namespace std;

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    void dfs(unordered_map<int, unordered_set<int>>& neighs, int u, vector<bool>& vis, unordered_set<int>& comp) {
        vis[u] = true;
        comp.insert(u);

        for (int v:neighs[u]) {
            if (!vis[v]) {
                dfs(neighs, v, vis, comp);
            }
        }

        return;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> neighs;

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            neighs[u].insert(v);
            neighs[v].insert(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                int isComplete = 1;

                unordered_set<int> comp;
                dfs(neighs, i, vis, comp);
                int c = comp.size();

                for (int node:comp) {
                    if (neighs[node].size() != c-1) isComplete = 0;
                }

                if (isComplete) ans++;
            }
        }

        return ans;
    }
};