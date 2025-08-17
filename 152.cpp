#include <vector>
#include <stdio.h>
#include <limits.h>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];

        int prevMin = nums[0];
        int prevMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int newPrevMin = std::min(std::min(nums[i], nums[i] * prevMax), nums[i] * prevMin);
            int newPrevMax = std::max(std::max(nums[i], nums[i] * prevMax), nums[i] * prevMin);

            max = std::max(max, newPrevMax);
            min = std::min(min, newPrevMin);

            prevMin = newPrevMin;
            prevMax = newPrevMax;
        }

        return max;
    }
};

int main() {
    Solution solution;

    std::vector<int> vec{2, 3, -2, 4};
    int res = solution.maxProduct(vec);
    printf("Res: %d\n", res);
}
