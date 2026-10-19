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

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int& pI, vector<int>& inorder) {
        if (inorder.size() == 0) return nullptr;

        int r = preorder[pI++];
        TreeNode* root = new TreeNode(r);
        
        int i=0;
        vector<int> left, right;
        while (inorder[i] != r) {
            left.push_back(inorder[i]);
            i++;
        };
        i++;
        while (i < inorder.size()) {
            right.push_back(inorder[i]);
            i++;
        }

        root->left = solve(preorder, pI, left);
        root->right = solve(preorder, pI, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pI = 0;
        TreeNode* ans = solve(preorder, pI, inorder);

        return ans;
    }
};