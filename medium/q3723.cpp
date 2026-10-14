using namespace std;

#include <string>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9*num < sum) return "";

        string s= "";

        while (sum >= 9) {
            s += '9';
            sum -= 9;
        }

        if (sum) s += ('0' + sum);

        int rem = num - s.size();

        for (int i=0; i<rem; i++) {
            s += '0';
        }

        return s;
    }
};