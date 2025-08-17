#include <vector>
#include <stdio.h>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            totalSum += nums[i];
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        std::vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};


int main() {
    Solution solution;
    std::vector<int> nums{3,3,6,8,16,16,16,18,20};
    bool val = solution.canPartition(nums);
    printf("Res: %d \n", val);
}
