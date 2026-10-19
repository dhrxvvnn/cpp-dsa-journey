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
    int solve(TreeNode* root, vector<int>& counts) {
        if (root == nullptr) return 0;

        counts[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            int odds = 0;

            for (int i:counts) {
                if (i%2 == 0) continue;

                odds++;
                if (odds == 2) {
                    counts[root->val]--;
                    return 0;
                }
            }

            counts[root->val]--;
            return 1;
        } 

        int left = solve(root->left, counts);
        int right = solve(root->right, counts);

        counts[root->val]--;
        return left + right;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);

        return solve(root, counts);
    }
};