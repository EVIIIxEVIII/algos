#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr long long mod = 1e9 + 7;
class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(nums.size(), vector<long long>(k, 0)));

        vector<vector<int>> g(n);
        int r = -1;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                r = i;
                continue;
            }

            g[parent[i]].push_back(i);
        }

        // dp[0][i][r] not selected i
        // dp[1][i][r] selected i

        dp[0][0][0] = 1;
        dp[1][0][(nums[0] % k)] = 1;

        auto dfs = [&](auto&& self, int v) -> void {
            dp[0][v][0] = 1;
            dp[1][v][(nums[v] % k)] = 1;

            for (int u : g[v]) {
                self(self, u);

                vector<vector<long long>> dp2(2, vector<long long>(k, 0));

                for (int a = 0; a < k; ++a) {
                    for (int b = 0; b < k; ++b) {
                        int r = (a + b) % k;

                        long long child_any = (dp[0][u][b] + dp[1][u][b]) % mod;

                        dp2[0][r] = (dp2[0][r] + (dp[0][v][a] * child_any) % mod) % mod;
                        dp2[1][r] = (dp2[1][r] + (dp[1][v][a] * dp[0][u][b]) % mod) % mod;
                    }
                }

                dp[0][v] = std::move(dp2[0]);
                dp[1][v] = std::move(dp2[1]);
            }
        };

        dfs(dfs, r);

        return (((dp[0][r][0] + dp[1][r][0]) % mod) + mod - 1) % mod;
    }
};
