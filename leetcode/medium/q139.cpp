using namespace std;

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool solve(string s, int st, unordered_set<string>& words, vector<int>& isfound) {
        if (s.size() == st) return true;

        if (isfound[st] == -1) return false;
        if (isfound[st] == 1) return true;

        string tmp = "";
        for (int i=st; i<s.size(); i++) {
            tmp += s[i];
            if (words.find(tmp) != words.end()) {
                bool found = solve(s, i+1, words, isfound);
                if (found) {
                    isfound[st] = 1;
                    return true;
                }
            } 
        }

        isfound[st] = -1;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word:wordDict) {
            words.insert(word);
        }
        vector<int> isfound(s.size(), 0);

        return solve(s, 0, words, isfound);
    }
};