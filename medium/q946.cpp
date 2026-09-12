#include <iostream>
using namespace std;

#include <vector>
#include <stack>

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;

    int p = 0;
    for (int i: pushed) {
        st.push(i);

        while (p< popped.size() && !st.empty() && popped[p] == st.top()) {
            st.pop();
            p++;
        }
    }

    return st.empty();
}