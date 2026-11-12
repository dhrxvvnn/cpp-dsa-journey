using namespace std;

#include <vector>
#include <numeric>
#include <climits>
#include <string>

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c:s) freq[c-'a']++;

        int mx = INT_MIN;
        char cmax;
        for (int i=0; i<26; i++) {
            if (freq[i] > mx) {
                mx = freq[i];
                cmax = 'a' + i;
            }
        }

        freq[cmax - 'a'] = 0;

        string init = "";
        init += cmax;
        vector<string> v(mx, init);

        int sum = accumulate(freq.begin(), freq.end(), 0);
        if (sum < mx-1) return "";

        int vptr = 0;
        int cptr = 0;
        while (cptr < 26) {
            int f = freq[cptr];
            char c = 'a' + cptr;

            while (f--) {
                v[vptr] += c;
                vptr++;
                vptr%= mx;
            }

            cptr++;
        }

        string ans = "";
        for (string vs:v) {
            ans += vs;
        }

        return ans;
    }
};