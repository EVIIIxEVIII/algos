#include <vector>
#include <limits.h>
#include <stdio.h>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());

        int ans = 1;

        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int bestMatch = 0;

            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    bestMatch = std::max(dp[j], bestMatch);
                }
            }

            if (bestMatch == 0) {
                dp[i] = 1;
            } else {
                dp[i] = bestMatch + 1;
                ans = std::max(dp[i], ans);
            }
        }

        return ans;
    }
};


int main() {
    Solution solution;

    //std::vector<int> nums{10,9,2,5,3,7,101,18};

    std::vector<int> nums{1,3,6,7,9,4,10,5,6};
    int len = solution.lengthOfLIS(nums);

    printf("Result: %d\n", len);
}
