using namespace std;

#include <string>

class Solution {
public:
    int minOperations(string s) {
        if (s.size() == 2 && s[1] < s[0]) return -1;

        bool issorted = true;

        char smallest = 'z';
        char largest = 'a';
        int small_count = 0;
        int large_count = 0;

        int n = s.size();

        for (int i=0; i<n; i++) {
            if (s[i] == smallest) small_count++;
            if (s[i] == largest) large_count++;

            if (s[i] < smallest) {
                small_count = 1;
                smallest = s[i];
            } 
            if (s[i] > largest) {
                large_count = 1;
                largest = s[i];
            }

            if (i != n-1) {
                if (s[i+1] < s[i]) issorted = false;
            }
        }

        if (issorted) return 0;

        if (s[0] == smallest || s[n-1] == largest) return 1;

        if (s[0] == largest && s[n-1] == smallest && small_count == 1 && large_count == 1) return 3;

        return 2;
    }
};