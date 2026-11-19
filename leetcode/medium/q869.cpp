using namespace std;

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<string> powers;

    Solution() {
        long long x = 1;

        for (int i = 0; i <= 30; i++) {
            string tmp = to_string(x);
            sort(tmp.begin(), tmp.end());

            powers.push_back(tmp);
            x *= 2;
        }
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        for (string pow : powers) {
            if (s == pow) return true;
        }

        return false;
    }
};