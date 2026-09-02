#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* h = nullptr;
    ListNode* back = nullptr;

    int sum = 0;
    ListNode* tmp = head->next;
    while(tmp != nullptr) {
        while (tmp->val != 0) {
            sum += tmp->val;
            tmp = tmp->next;
        }

        if (h == nullptr) {
            h = back = new ListNode(sum);
        } else {
            back->next = new ListNode(sum);
            back = back->next;
        }

        sum = 0;
        tmp = tmp->next;
    }

    return h;
}