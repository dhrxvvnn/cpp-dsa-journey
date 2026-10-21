using namespace std;

#include <string>
#include <unordered_set>
#include <map>

class Solution {
public:
    string solve(string s, unordered_set<char>& uniqs) {
        if (uniqs.size() == 0) return "";

        map<char, pair<int, int>> occur;

        for (int i=0; i<s.size(); i++) {
            char c = s[i];

            if (uniqs.find(c) == uniqs.end()) continue;

            if (occur.find(c) == occur.end()) {
                occur[c] = {-1,-1};
            }

            if (occur[c].first == -1) occur[c].first = i;
            occur[c].second = i;
        }

        char ans;
        int idx;
        for (auto [c1, range1] : occur) {
            auto [st1, end1] = range1;
            bool isans = true;
            for (auto [c2, range2] : occur) {
                auto [st2, end2] = range2;
                if (c1 == c2) continue;

                if (st1 > end2) {
                    isans = false;
                    break;
                }
            }

            if (isans) {
                ans = c1;
                idx = st1;
                break;
            }
        }

        uniqs.erase(ans);
        string nxt = solve(s.substr(idx+1, s.size()-idx-1), uniqs);

        return ans + nxt;
    }

    string removeDuplicateLetters(string s) {
        unordered_set<char> uniqs;

        for (char c:s) {
            uniqs.insert(c);
        }

        return solve(s, uniqs);
    }
};