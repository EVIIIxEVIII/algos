#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<std::vector<long>> dp(coins.size(), std::vector<long>(amount+1, 0));

        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int j = coins[0]; j <= amount; ++j) {
            dp[0][j] = dp[0][j - coins[0]];
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                int top = i - 1 >= 0 ? dp[i - 1][j] : 0;

                if (j >= coins[i]) {
                    dp[i][j] = top + (dp[i][j - coins[i]]);
                } else {
                    dp[i][j] = top;
                }
            }
        }

        return dp[coins.size() - 1][amount];
    }
};



