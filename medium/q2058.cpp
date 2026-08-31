#include <iostream>
using namespace std;

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (head == nullptr 
    || head->next == nullptr 
    || head->next->next == nullptr 
    || head->next->next->next == nullptr) return {-1,-1};

    ListNode* prev = head;
    ListNode* tmp = head->next;
    ListNode* nxt = head->next->next;

    int st = -1;
    int end = -1;

    int mn = INT_MAX;

    int i = 1;
    int found = 0;
    while (nxt != nullptr) {
        if ((tmp->val > prev->val && tmp->val > nxt->val) || (tmp->val < prev->val && tmp->val < nxt->val)) {
            found++;
            if (st == -1) st = i;
            if (end != -1) mn = min(mn, i-end);
            end = i;
        }

        prev = tmp;
        tmp = nxt;
        nxt = nxt->next;
        i++;
    }

    if (found < 2) return {-1, -1};

    int mx = end - st;

    return {mn, mx};
}

int main () {

    return 0;
}