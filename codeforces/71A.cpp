#include <iostream>
using namespace std;
#include <vector>
#include <string>

string convert(string s) {
    if (s.size() <= 10) return s;

    string ans = "";
    ans += s[0];
    int num = s.size()-2;
    ans += to_string(num);
    ans += s[s.size()-1];

    return ans;
}

int main () {
    int n;
    cin >> n;

    vector<string> input;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    for (int i=0; i<n; i++) {
        cout << convert(input[i]) << endl;
    }

    return 0;
}