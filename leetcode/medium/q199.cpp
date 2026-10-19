#include <iostream>
using namespace std;

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) return {};

    vector<int> ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i=0; i<n; i++) {
            TreeNode* tmp = q.front();
            q.pop();
            if (i == n-1) ans.push_back(tmp->val);

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
    }

    return ans;
}

int main () {
    return 0;
}