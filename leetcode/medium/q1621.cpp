#include <iostream>
using namespace std;

#include <vector>

int solve(int n, int k, vector<vector<int>>& dp) {
    if (dp[n][k] != -1) return dp[n][k];

    if (k > n-1) return 0;

    if (k == 0) return 1;

    if (n == 1) return 0;

    if (n == 2 && k == 1) return 1;

    int ans = 0;

    ans += solve(n-1, k, dp);
    ans = ans%(1000000007);
    for (int i=1; i<n; i++) {
        ans += solve(n-i, k-1, dp);
        ans = ans%(1000000007);
    }

    return dp[n][k] = ans%(1000000007);
}

int numberOfSets(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    return solve(n, k, dp);
}