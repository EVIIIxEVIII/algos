#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        dp[0][0][grid[0][0]] = true;

        auto explore = [&](int i, int j) -> void {
           for (int k = 0; k < 1024; ++k) {
               if (i - 1 >= 0) {
                   dp[i][j][k] = dp[i-1][j][grid[i][j] ^ k] || dp[i][j][k];
               }

               if (j - 1 >= 0) {
                   dp[i][j][k] = dp[i][j-1][grid[i][j] ^ k] || dp[i][j][k];
               }
           }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                explore(i, j);
            }
        }

        int ans = 1024;
        for (int k = 0; k < 1024; ++k) {
            if (dp[n-1][m-1][k]) {
                ans = min(k, ans);
                break;
            }
        }

        return ans;
    }
};
