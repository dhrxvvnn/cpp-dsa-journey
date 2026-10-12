#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, vector<long> targetSum, int t, int& ans) {
        if (root == nullptr) return;

        for (long i:targetSum) {
            if (i == root->val) ans++;
        }

        vector<long> v;
        for (long i:targetSum) {
            v.push_back(i - root->val);
        }
        v.push_back(t);

        solve(root->left, v, t, ans);
        solve(root->right, v, t, ans);
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        solve(root, {targetSum}, targetSum, ans);

        return ans;
    }
};