#include <iostream>
using namespace std;

#include <vector>
#include <stack>

string reverseParentheses(string s) {
    stack<string> st;

    string curr = "";

    for (char c:s) {
        if (isalpha(c)) curr += c;
        else {
            if (c == '(') {
                st.push(curr);
                curr = "";
            } else {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
        }
    }

    return curr;
}