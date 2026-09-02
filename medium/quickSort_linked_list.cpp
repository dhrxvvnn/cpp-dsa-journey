#include <iostream>
using namespace std;

#include <list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

pair<ListNode*, ListNode*> solve(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return {head, head};
    }

    ListNode* pivot = head;
    ListNode* l;
    ListNode* r;
    ListNode* lback;
    ListNode* rback;
    l = r = lback = rback = nullptr;

    ListNode* tmp = head->next;
    while (tmp!= nullptr) {
        if (tmp->val <= pivot->val) {
            if (lback != nullptr) {
                lback->next = tmp;
                lback = tmp;
            } else {
                l = lback = tmp;
            }
        } else {
            if (rback != nullptr) {
                rback->next = tmp;
                rback = tmp;
            } else {
                r = rback = tmp;
            }
        }

        tmp = tmp->next;
    }

    if (lback) lback->next = nullptr;
    auto [h1, b1] = solve(l);
    if (rback) rback->next = nullptr;
    auto [h2, b2] = solve(r);

    pivot->next = h2;
    if (b1 != nullptr) {
        b1->next = pivot;
        head = h1;
    } else {
        head = pivot;
    }

    if (rback) {
        return {head, rback};
    } else {
        return {head, pivot};
    }
}

ListNode* QSLL(ListNode* head) {
    return solve(head).first;
}

int main () {
    ListNode* head = new ListNode(12);
    head->next = new ListNode(20);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(16);
    head->next->next->next->next = new ListNode(42);

    head = QSLL(head);

    ListNode* tmp = head;
    while (tmp!= nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout <<endl;

    return 0;
}