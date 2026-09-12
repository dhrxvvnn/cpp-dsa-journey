#include <iostream>
using namespace std;

#include <vector>
#include <stack>

int minInsertions(string s) {
    stack<char> st;

    int ans = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else {
            if (s[i+1] != ')') ans++;
            else i++;

            if (st.empty()) ans++;
            else st.pop();
        }
    }

    while (!st.empty()) {
        ans += 2;
        st.pop();
    }

    return ans;
}