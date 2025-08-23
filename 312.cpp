#include <vector>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        std::vector<int> n(nums.size() + 2, 1);
        for (int i = 0; i < nums.size(); ++i) n[i + 1] = nums[i];

        std::vector<std::vector<int>> dp(nums.size() + 2, std::vector<int>(nums.size() + 2, -1));
        return dfs(1, nums.size(), dp, n);
    }

    int dfs(int l, int r, std::vector<std::vector<int>>& dp, std::vector<int>& nums) {
        if (l > r) {
            return 0;
        }

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        int coins = 0;
        for (int i = l; i <= r; i++) {
            coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(l, i - 1, dp, nums) + dfs(i + 1, r, dp, nums);
            dp[l][r] = std::max(dp[l][r], coins);
        }

        return dp[l][r];
    }
};
