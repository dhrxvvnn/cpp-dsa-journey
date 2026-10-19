#include <iostream>
using namespace std;

#include <vector>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int numComponents(ListNode* head, vector<int>& nums) {
    set<int> s;

    for (int i:nums) s.insert(i);

    ListNode* tmp = head;

    int ans = 0;
    while (tmp != nullptr) {
        while (tmp != nullptr && s.find(tmp->val) == s.end()) tmp = tmp->next;

        if (tmp == nullptr) break;

        ans++;
        while (tmp != nullptr && s.find(tmp->val) != s.end()) tmp = tmp->next; 
    }

    return ans;
}

int main () {

    return 0;
}