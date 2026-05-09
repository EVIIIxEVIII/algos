#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int zs = 0;
        int os = 0;

        for (char c : s) {
            if (c == '0') zs++;
            else os++;
        }

        int ans = max(0, os - 1);
        ans = min(ans, zs);

        if (n >= 2) {
            int another_ans = 0;
            if (s[0] != '1') another_ans++;
            if (s[n-1] != '1') another_ans++;

            for (int i = 1; i < n - 1; ++i) {
                if (s[i] == '1') another_ans++;
            }

            ans = min(ans, another_ans);
        }

        return ans;
    }
};
