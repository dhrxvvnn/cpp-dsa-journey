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

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = 0;

    ListNode* tmp = head;
    while (tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }

    int p = n/k;
    int rem = n%k;
    tmp = head;
    vector<ListNode*> ans;
    for (int i=0; i<k; i++) {
        ans.push_back(tmp);

        if (tmp == nullptr) continue;

        for (int j=0; j<p; j++) {
            if (j == p-1 && !rem && tmp != nullptr) {
                ListNode* nxt = tmp->next;
                tmp->next = nullptr;
                tmp = nxt;
                continue;
            }

            if (tmp != nullptr) tmp = tmp->next;
        }

        if (rem) {
            if (tmp != nullptr) {
                ListNode* nxt = tmp->next;
                tmp->next = nullptr;
                tmp = nxt;
            }
            rem--;
        }
    }

    return ans;
}

int main () {

    return 0;
}