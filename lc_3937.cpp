#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int min_dist(int a, int b, int k) {
        return min((b - a + k) % k, (a - b + k) % k);
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
// fucking leetcode and your fucking 503 fuck you all stupid vibe coders.
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] % k;
        }

        long long ans = INT_MAX;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i == j) continue;

                long long local = 0;
                for (int t = 0; t < n; ++t) {
                    if (t % 2 == 0) {
                        local += min_dist(nums[t], i, k);
                    } else {
                        local += min_dist(nums[t], j, k);
                    }
                }

                ans = min(ans, local);
            }
        }

        return ans;
    }
};
