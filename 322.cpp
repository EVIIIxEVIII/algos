#include <vector>
#include <limits.h>
#include <stdio.h>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};


int main() {
    Solution solution;

    std::vector<int> coins{2};
    int amount = 3;

    int sol = solution.coinChange(coins, amount);
    printf("Solution: %d \n", sol);

}
