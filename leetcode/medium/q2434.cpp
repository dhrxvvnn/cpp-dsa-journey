using namespace std;

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);

        for (char c:s) {
            freq[c-'a']++;
        }

        string ans = "";
        string stack = "";
        
        int i=0;
        while (i<s.size()) {
            if (stack.size() == 0) {
                stack.push_back(s[i]);
                freq[s[i]-'a']--;
                i++;
                continue;
            } 

            int idx = stack.back() - 'a';
            char smaller;
            bool small_found = false;
            for (int i=0; i<idx; i++) {
                if (freq[i]) {
                    smaller = 'a' + i;
                    small_found = true;
                    break;
                }
            }

            if (!small_found) {
                ans += stack.back();
                stack.pop_back();
                continue;
            }

            while (s[i] != smaller) {
                stack.push_back(s[i]);
                freq[s[i]-'a']--;
                i++;
            }
            ans += s[i];
            freq[s[i]-'a']--;
            i++;
        }

        reverse(stack.begin(), stack.end());
        ans += stack;

        return ans;
    }
};