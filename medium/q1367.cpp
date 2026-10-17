using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    void find(TreeNode* root, int x, vector<TreeNode*>& roots) {
        if (root == nullptr) return;

        if (root->val == x) roots.push_back(root);

        find(root->left, x, roots);
        find(root->right, x, roots);

        return;
    }

    bool isPresent(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;

        if (root == nullptr) return false;
        if (root->val != head->val) return false;

        bool left = isPresent(head->next, root->left);
        if (left) return true;
        return isPresent(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> roots;

        find(root, head->val, roots);

        for (auto root : roots) {
            if (isPresent(head, root)) return true;
        }

        return false;
    }
};