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

ListNode* solve(ListNode* head, int k) {
    int n = 0;
    ListNode* tmp = head;
    while (tmp != nullptr) {
        n++;
        if (n == k) break;
        tmp = tmp->next;
    }

    if (n == 0) return head;

    if (n%2 == 1) {
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr) {
            count ++;
            if (count == n) break;
            curr= curr->next; 
        }
        curr->next = solve(curr->next, k+1);
    } else {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;;
        int count = 0;
        while (curr!= nullptr) {
            count++;
            ListNode* tmpnxt = curr->next;
            curr->next = prev;
            prev = curr;
            if (count == n) {
                nxt = tmpnxt;
                break;
            }
            curr = tmpnxt;
        }

        head->next = solve(nxt, k+1);
        return curr;
    }

    return head;
}

ListNode* reverseEvenLengthGroups(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

    return solve(head, 1);
}

int main () {

    return 0;
}