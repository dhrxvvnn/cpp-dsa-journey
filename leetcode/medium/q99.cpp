using namespace std;

#include <algorithm>

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
    void dfs(TreeNode* root, TreeNode*& node1, TreeNode*& node2, bool& nodefound, TreeNode*& prev) {
        if (root == nullptr) return;

        dfs(root->left, node1, node2, nodefound, prev);

        if (!nodefound) {
            prev = root;
            nodefound = true;
        } else {
            if (prev->val > root->val) {
                if (node1 == nullptr) {
                    node1 = prev;
                    node2 = root;
                } else {
                    node2 = root;
                    return;
                }
            }

            prev = root;
        }

        dfs(root->right, node1, node2, nodefound, prev);

        return;
    }

    void recoverTree(TreeNode* root) {
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
        bool nodefound = false;
        TreeNode* prev = nullptr;

        dfs(root, node1, node2, nodefound, prev);

        swap(node1->val, node2->val);
        return;
    }
};