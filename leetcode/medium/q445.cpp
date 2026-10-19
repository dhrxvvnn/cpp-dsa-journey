#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1->val == 0) return l2;
    if (l2->val == 0) return l1;

    ListNode* prev = nullptr;
    ListNode* tmp = l1;
    while(tmp != nullptr) {
        ListNode* nxt = tmp->next;
        tmp->next = prev;
        if (nxt == nullptr) l1 = tmp;
        prev = tmp;
        tmp = nxt;
    }

    prev = nullptr;
    tmp = l2;
    while(tmp != nullptr) {
        ListNode* nxt = tmp->next;
        tmp->next = prev;
        if (nxt == nullptr) l2 = tmp;
        prev = tmp;
        tmp = nxt;
    }

    ListNode* head = nullptr;
    ListNode* tmp1 = l1;
    ListNode* tmp2 = l2;

    int carry = 0;
    while (tmp1!=nullptr && tmp2!=nullptr) {
        int sum = tmp1->val + tmp2->val + carry;
        carry = sum/10;
        int digit = sum%10;
        if (head != nullptr) {
            tmp = new ListNode(digit);
            tmp->next = head;
            head = tmp;
        } else {
            head = new ListNode(digit);
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    while (tmp1 != nullptr) {
        int sum = tmp1->val +carry;
        carry = sum/10;
        int digit = sum%10;
        tmp = new ListNode(digit);
        tmp->next = head;
        head = tmp;

        tmp1 = tmp1->next;
    }
    
    while (tmp2 != nullptr) {
        int sum = tmp2->val +carry;
        carry = sum/10;
        int digit = sum%10;
        tmp = new ListNode(digit);
        tmp->next = head;
        head = tmp;

        tmp2 = tmp2->next;
    }

    if (carry == 1) {
        tmp = new ListNode(1);
        tmp->next = head;
        head = tmp;
    }

    return head;
}

int main () {

    return 0;
}