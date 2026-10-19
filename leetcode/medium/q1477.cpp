#include <iostream>
using namespace std;

#include <vector>

int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();

    int mn = INT_MAX; // min subarray found
    vector<int> mnsa(n+1); // min subarray to the right of every element
    mnsa[n] = INT_MAX;

    int sum = 0;
    int r = n-1;
    for (int i=n-1; i>=0; i--) {
        sum += arr[i];

        while (sum > target) {
            sum -= arr[r];
            r--;
        }

        if (sum == target && r-i+1 < mn) mn = r-i+1;
        mnsa[i] = mn;
    }

    int ans = INT_MAX;

    sum = 0;
    int l = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];

        while (sum > target) {
            sum -= arr[l];
            l++;
        }

        if (sum == target && mnsa[i+1] != INT_MAX) {
            ans = min(ans, i-l+1 + mnsa[i+1]);
        }
    }

    return ans == INT_MAX ? -1: ans;
}