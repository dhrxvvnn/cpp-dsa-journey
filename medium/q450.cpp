#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } 

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->left == nullptr) {
            TreeNode* tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }

        if (root->right == nullptr) {
            TreeNode* tmp = root;
            root = root->left;
            delete tmp;
            return root;
        }

        auto tmp = findMin(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
        return root;
    }
};