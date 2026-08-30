#include<iostream>
using namespace std;

class stack {
    int nums[100];
    int topIndex;

public:
    stack () {
        topIndex = 0;
    }

    void push(int x) {
        if (topIndex == 100) cout << "stack overflow" << endl;

        nums[topIndex++] = x;
    }

    void pop() {
        if (topIndex == 0) cout << "stack underflow" << endl;

        topIndex--;
    }

    int top() {
        return nums[topIndex-1];
    }

    bool isEmpty() {
        return topIndex == 0;
    }

    int size() {
        return topIndex;
    }
};

int main () {
    stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.isEmpty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}