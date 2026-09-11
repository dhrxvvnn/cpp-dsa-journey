#include <iostream>
using namespace std;

#include <vector>
#include <unordered_set>
#include <string>

pair<vector<int>& , vector<char>&> solve(vector<int>& nums, vector<char>& ops, unordered_set<char> op) {
    vector<int> numsN;
    vector<char> opsN;

    for (int i=0; i<ops.size(); i++) {
        if (op.find(ops[i]) == op.end()) {
            numsN.push_back(nums[i]);
            opsN.push_back(ops[i]);
            continue;
        }

        int a = nums[i];
        int b = nums[i+1];

        int c;
        if (ops[i] == '+') c = a + b;
        else if (ops[i] == '-') c = a - b;
        else if (ops[i] == '*') c = a * b;
        else c = a / b;

        nums[i+1] = c;
    }

    numsN.push_back(nums[nums.size() -1]);

    nums = numsN;
    ops = opsN;
    return {nums, ops};
}

int calculate(string s) {
    vector<int> nums;
    vector<char> ops;

    int n = s.size();
    for(int i=0; i<n; i++) {
        char c = s[i];

        if (c == ' ') continue;

        if (c == '+' || c == '-' || c == '*' || c == '/') {ops.push_back(c); continue;}

        string num = "";

        while (isdigit(s[i])) {
            num += s[i];
            i++;
        }

        i--;

        nums.push_back(stoi(num));
    }

    solve(nums, ops, {'*', '/'});
    solve(nums, ops, {'+', '-'});

    return nums[0];
}