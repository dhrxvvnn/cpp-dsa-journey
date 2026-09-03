#include <iostream>
using namespace std;

#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<pair<int, TreeNode*>> st;
        st.push({0, root});

        while (!st.empty()) {
            auto& curr = st.top();

            if (curr.first == 1) {
                ans.push_back(curr.second->val);
                st.pop();
                continue;
            }

            curr.first = 1;

            if (curr.second->right != nullptr)
                st.push({0, curr.second->right});

            if (curr.second->left != nullptr)
                st.push({0, curr.second->left});
        }

        return ans;
    }
};