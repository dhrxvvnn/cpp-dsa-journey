#include <iostream>
using namespace std;

int maximumGain(string s, int x, int y) {
    pair<string, string> p;

    if (x >= y) {
        p = {"ab", "ba"};
    } else { p = {"ba", "ab"}; }

    int ans = 0;

    string f = p.first;
    string tmp = "";
    int point = max(x, y);
    for (char c:s) {
        if (c != f[1]) tmp += c;
        else {
            if (!tmp.empty() && tmp.back() == f[0]) {
                tmp.pop_back();
                ans += point;
            } else { tmp += c;}
        }
    }

    f = p.second;
    string tmp2 = "";
    point = min(x, y);
    for (char c:tmp) {
        if (c != f[1]) tmp2 += c;
        else {
            if (!tmp2.empty() && tmp2.back() == f[0]) {
                tmp2.pop_back();
                ans += point;
            } else { tmp2 += c;}
        }
    }

    return ans;
}