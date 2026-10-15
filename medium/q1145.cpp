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
    int count(TreeNode* root) {
        if (root == nullptr) return 0;

        return count(root->left) + count(root->right) + 1;
    }

    TreeNode* find(TreeNode* root, int x) {
        if (root == nullptr) return nullptr;

        if (root->val == x) return root;

        auto left = find(root->left, x);
        if (left) return left;

        return find(root->right, x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto node = find(root, x);

        int lnodes = count(node->left);
        int rnodes = count(node->right);

        int rem = n - lnodes - rnodes - 1;

        if (
            rem > lnodes + rnodes ||
            lnodes > rem + rnodes ||
            rnodes > rem + lnodes
        ) return true;

        return false;
    }
};