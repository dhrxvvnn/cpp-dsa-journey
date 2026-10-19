#include <iostream>
using namespace std;

#include <map>
#include <vector>

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int n = nums1.size();

    map<int, int> m;
    m[0] = 0;

    int sum = 0;
    for (int i=0; i<n; i++) {
        int x = abs(nums1[i] - nums2[i]);
        m[x]++;
        sum += x;
    }

    for (auto [x, y] : m) {
        cout << x << " " << y << endl;
    }

    cout << endl << endl;

    long t = k1 + k2;
    if (m.size() == 1 || t >= sum) return 0;

    for (auto i=m.rbegin(); i!=m.rend(); i++) {
        auto [x, y] = *i;
        int tmpx = x;
        int tmpy = y;

        while (tmpx > 0 && t > y) {
            tmpx -= 1;
            t -= y;
        }

        cout << x << " " << y << endl;
        cout << tmpx << " " << t << endl;
        cout << endl << endl;

        if (t == 0) {
            m.erase(x);
            m[tmpx] += y;
            break;
        }
        if (x == 0) {
            m.erase(x);
            continue;
        }

        m.erase(x);
        m[tmpx] += y -t;
        m[tmpx-1] += t;
        break;
    }

    long long ans = 0;

    for (auto [x, y] : m) {
        cout << x << " " << y << endl;
        long sq = x*x;
        ans += y * sq;
    }

    return ans;
}