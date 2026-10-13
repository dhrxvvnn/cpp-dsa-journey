#include <iostream>
using namespace std;

#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int n = q.size();
            long long st, end;
            long long base = q.front().second;

            for (int i=0; i<n; i++) {
                auto [tmp, idx] = q.front();

                idx -= base;

                if (i == 0) st = idx;
                if (i == n-1) end = idx;

                if (tmp->left) q.push({tmp->left, 2*idx});
                if (tmp->right) q.push({tmp->right, 2*idx + 1});

                q.pop();
            }
            
            int currans = end-st+1;
            ans = max(ans, currans);
        }

        return ans;
    }
};