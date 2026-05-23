#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)  {
                zs++;
            }
        }

        int n = nums.size();
        long long ans = 0;
        for (int i = n - 1; i >= n - zs; --i) {
            if (nums[i] != 0)  {
                ans++;
            }
        }

        return ans;
    }
};
