#include <vector>
#include <stdio.h>
#include <cmath>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int m = nums.size();
        int n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            n += nums[i];
        }

        if (target > n || target < -n) {
            return 0;
        }

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(2*n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        dp[0][n] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= 2*n; ++j) {
                int top = i - 1 >= 0 ? dp[i-1][j] : 0;

                if (top > 0) {
                    int realSum = j - n;
                    int backward = realSum - nums[i - 1] + n;
                    int forward = realSum + nums[i - 1] + n;

                    dp[i][backward] += top;
                    dp[i][forward] += top;
                }
            }
        }

        return dp[m][target + n];
    }
};


int main() {

    Solution solution;

    std::vector<int> vec{1, 1, 1, 1, 1};
    int target = 3;
    int res = solution.findTargetSumWays(vec, target);

    printf("Res: %d\n", res);
}
