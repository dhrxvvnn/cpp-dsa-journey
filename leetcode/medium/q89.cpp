#include <iostream>
using namespace std;

#include <vector>

vector<int> grayCode(int n) {
    if (n == 1) return {0, 1};

    int add = 1;
    for (int k=2; k<=n; k++) add *= 2;

    vector<int> prev = grayCode(n-1);
    
    vector<int> ans;
    for (int i:prev) ans.push_back(i);
    for (int i=prev.size()-1; i>=0; i--) {
        ans.push_back(prev[i] + add);
    }

    return ans;
}