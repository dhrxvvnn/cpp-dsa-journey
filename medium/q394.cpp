#include <iostream>
using namespace std;

#include <stack>
#include <string>

string decodeString(string s) {
    stack<int> freq;
    stack<string> ans;
    ans.push("");

    int num = 0;
    for (char i:s) {
        if (isdigit(i)) {
            num *= 10;
            num += i-'0';
            continue;
        }

        if (isalpha(i)) {
            ans.top() += i;
            continue;
        }

        if (i == '[') {
            freq.push(num);
            ans.push("");
            num = 0;
            continue;
        }

        string tmp = ans.top();
        ans.pop();
        int f = freq.top();
        freq.pop();

        for (int j=0; j<f; j++) {
            ans.top() += tmp;
        }
    }

    return ans.top();
}