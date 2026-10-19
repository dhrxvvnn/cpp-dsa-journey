#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* back = head;
    ListNode* tmp = head->next;

    while (tmp != nullptr) {
        if (tmp->val >= back->val) {
            back = tmp;
            tmp = tmp->next;
        } else {
            ListNode* nxt = tmp->next;

            if (head->val >= tmp->val) {
                tmp->next = head;
                head = tmp;
            } else {
                ListNode* tmp2 = head;
                while (tmp2->next->val < tmp->val) {
                    tmp2 = tmp2->next;
                }
                ListNode* nxt2 = tmp2->next;
                tmp2->next = tmp;
                tmp->next = nxt2;
            }

            back->next = nxt;
            tmp = nxt;
        }
    }

    return head;
}


int main () {
    ListNode* head = new ListNode(12);
    head->next = new ListNode(20);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(16);
    head->next->next->next->next = new ListNode(42);

    head = insertionSortList(head);

    ListNode* tmp = head;
    while (tmp!= nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout <<endl;

    return 0;
}