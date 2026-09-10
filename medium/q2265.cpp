#include <iostream>
using namespace std;

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> solve(TreeNode* root) {
    if (root == nullptr) return {0, 0, 0}; //{ans, sum, no of nodes}

    int ans = 0;

    auto i = solve(root->left);
    auto j = solve(root->right);

    ans += i[0] + j[0];

    int sum = i[1] + j[1] + root->val;
    int nodes = i[2] + j[2] + 1;
    int avg = sum/nodes;
    if (avg == root->val) {ans++;}

    return {ans, sum, nodes};
}

int averageOfSubtree(TreeNode* root) {
    return solve(root)[0];
}