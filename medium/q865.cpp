#include <iostream>
using namespace std;

#include <unordered_set>
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
    TreeNode* solve(TreeNode* root, unordered_set<TreeNode*>& s) {
        if (root == nullptr) return nullptr;
        if (s.find(root) != s.end()) return root;

        auto left = solve(root->left, s);
        auto right = solve(root->right, s);

        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_set<TreeNode*> s;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            s.clear();

            int n = q.size();

            for (int i=0; i<n; i++) {
                TreeNode* tmp = q.front();

                s.insert(tmp);

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);

                q.pop();
            }
        }

        TreeNode* ans = solve(root, s);

        return ans;
    }
};