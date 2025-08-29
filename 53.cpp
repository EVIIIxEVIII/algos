#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int maxSumLocal = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (maxSumLocal <= 0 || nums[i] + maxSumLocal <= 0) {
                maxSumLocal = nums[i];
            } else {
                maxSumLocal += nums[i];
            }

            maxSum = std::max(maxSum, maxSumLocal);
        }

        return std::max(maxSumLocal, maxSum);
    }
};
