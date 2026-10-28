using namespace std;

#include <vector>
#include <string>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();

        vector<int> ogfreq(27, 0);
        for (int i=0; i<s1.size(); i++) {
            ogfreq[s1[i] - 'a']++;
        }

        vector<int> freq(27, 0);
        
        int left = 0;
        for (int right=0; right<s2.size(); right++) {
            char c = s2[right];

            int x = c - 'a';
            freq[x]++;
            while (freq[x] > ogfreq[x]) {
                freq[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 != n1) continue;
            
            bool issame = true;
            for (int j=1; j<=26; j++) {
                if (freq[j] != ogfreq[j]) {
                    issame = false;
                    break;
                }
            }
            if (issame) return true;
        }

        return false;
    }
};