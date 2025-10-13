#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int prev = INT_MIN;
        for (int i = 0; i < n; ++i) {


        }

        return ans;
    }
};
