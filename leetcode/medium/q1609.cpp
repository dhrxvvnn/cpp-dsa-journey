using namespace std;

#include <queue>

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = -1;
        while(!q.empty()) {
            level++;
            int n = q.size();

            if (level%2 == 0) {
                int prev = -1;

                for (int i=0; i<n; i++) {
                    auto node = q.front();

                    if ((node->val)%2 == 0 || node->val <= prev) return false;
                    prev = node->val;

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);

                    q.pop();
                }
            } else {
                int prev = INT_MAX;

                for (int i=0; i<n; i++) {
                    auto node = q.front();

                    if ((node->val)%2 == 1 || node->val >= prev) return false;
                    prev = node->val;

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);

                    q.pop();
                }
            }
        }

        return true;
    }
};