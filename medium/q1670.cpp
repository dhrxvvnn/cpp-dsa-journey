#include <iostream>
using namespace std;

#include <deque>

class FrontMiddleBackQueue {
    deque<int> q1, q2;
    int n1, n2;
public:
    FrontMiddleBackQueue() {
        n1 = n2 = 0;
    }
    
    void pushFront(int val) {
        q1.push_front(val);
        n1++;
        if (n1 > n2) {
            q2.push_front(q1.back());
            q1.pop_back();
            n1--;
            n2++;
        }
    }
    
    void pushMiddle(int val) {
        if (n1 == n2) {
            q2.push_front(val);
            n2++;
        } else {
            q1.push_back(val);
            n1++;
        }
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        n2++;
        if (n2 == n1+2) {
            q1.push_back(q2.front());
            q2.pop_front();
            n1++;
            n2--;
        }
    }
    
    int popFront() {
        if (n2 == 0) return -1;

        if (n1 == 0) {
            int val = q2.front();
            q2.pop_front();
            n2--;
            return val;
        }

        int val = q1.front();
        q1.pop_front();
        n1--;
        if (n2 == n1+2) {
            q1.push_back(q2.front());
            q2.pop_front();
            n1++;
            n2--;
        }
        return val;
    }
    
    int popMiddle() {
        if (n2 == 0) return -1;

        if (n1 == n2) {
            int val = q1.back();
            q1.pop_back();
            n1--;
            return val;
        } else {
            int val = q2.front();
            q2.pop_front();
            n2--;
            return val;
        }
    }
    
    int popBack() {
        if (n2 == 0) return -1;

        int val = q2.back();
        q2.pop_back();
        n2--;
        if (n1 == n2+1) {
            q2.push_front(q1.back());
            q1.pop_back();
            n1--;
            n2++;
        }
        return val;
    }
};