#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        vector<int> ones;
        vector<int> twos;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1)
                ones.push_back(i);
            if (nums[i] == 2)
                twos.push_back(i);
        }

        for (int i : twos) {
            auto it = upper_bound(ones.begin(), ones.end(), i);

            if (it != ones.end()) {
                ans = min(abs(i - *it), ans);
            }

            if (it != ones.begin()) {
                ans = min(ans, abs(i - *prev(it)));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
