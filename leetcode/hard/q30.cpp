using namespace std;

#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    void solve(string s, int n, int m, unordered_map<string, int>& ogfreq, int st, vector<int>& ans) {
        unordered_map<string, int> freq;
        int left = st;
        for (int right=st; right<s.size(); right += n) {
            string curr = s.substr(right, n);
            freq[curr]++;

            while (freq[curr] > ogfreq[curr]) {
                string last = s.substr(left, n);
                freq[last]--;
                left += n;
            }

            if (right - left + n != m*n) continue;

            ans.push_back(left);
        }

        return;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> ogfreq;
        for (auto word:words) {
            ogfreq[word]++;
        }
        int n = words[0].size();
        int m = words.size();

        vector<int> ans;

        for (int i=0; i<n; i++) {
            solve(s, n, m, ogfreq, i, ans);
        }

        return ans;
    }
};