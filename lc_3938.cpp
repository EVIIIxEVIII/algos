#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long max_subarray_sum(vector<int>& a) {
        long long current = a[0];
        long long ans = LLONG_MIN;

        for (int i = 1; i < a.size(); ++i) {
            if (a[i] > current + a[i] * 1LL) {
                current = a[i];

                if (i != a.size() - 1) {
                    ans = current;
                }
            } else {
                current += a[i] * 1LL;
                ans = max(ans, current);
            }
        }

        return ans;
    }

    long long max_subarray_sum_2(vector<int>& a) {
        long long current = a[0];
        long long ans = LLONG_MIN;

        for (int i = 1; i < a.size(); ++i) {
            ans = max(ans, current + a[i]);
            current = max(current + (long long)a[i], (long long)a[i]);
        }

        return ans;
    }

    int maxScore(vector<vector<int>>& grid) {
        // is this shit just a max subarray sum on the grid?

        long long ans = LLONG_MIN;
        for (int i = 1; i < grid.size() - 1; ++i) {
            ans = max(ans, max_subarray_sum(grid[i]));
        }

        vector<vector<int>> cols(grid[0].size(), vector<int>(grid.size()));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                cols[j][i] = grid[i][j];
            }
        }

        for (int i = 1; i < cols.size() - 1; ++i) {
            ans = max(ans, max_subarray_sum(cols[i]));
        }

        ans = max(ans, max_subarray_sum_2(cols.front()));
        ans = max(ans, max_subarray_sum_2(cols.back()));
        ans = max(ans, max_subarray_sum_2(grid.front()));
        ans = max(ans, max_subarray_sum_2(grid.back()));

        return ans;
    }
};
