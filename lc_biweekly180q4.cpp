#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;
class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        long long ans = 0;
        string bit_str;

        vector<pair<int,int>> a;
        for (int i = 0; i < (int)nums1.size(); ++i) {
            if (nums0[i] != 0) {
                a.push_back({nums1[i], INT_MAX - nums0[i]});
            } else {
               for (int j = 0; j < nums1[i]; ++j) {
                   bit_str.push_back('1');
               }
            }
        }

        sort(a.begin(), a.end(), greater<pair<int,int>>());
        for (int i = 0; i < a.size(); ++i) {
            auto [ones, zs] = a[i];
            int zeros = INT_MAX - zs;
            for (int i = 0; i < ones; ++i) {
                bit_str.push_back('1');
            }
            for (int i = 0; i < zeros; ++i) {
                bit_str.push_back('0');
            }
        }

        for (int i = 0; i < bit_str.size(); ++i) {
            ans = (ans*2 + (bit_str[i]-'0')) % mod;
        }

        return ans;
    }
};
