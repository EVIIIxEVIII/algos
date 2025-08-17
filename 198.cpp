#include <vector>


class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> helper(nums.size());

        if(nums.size() == 1) return nums.at(0);

        helper.at(0) = nums.at(0);
        helper.at(1) = std::max(nums.at(0), nums.at(1));

        for (int i = 2; i < nums.size(); ++i) {
            helper.at(i) = std::max(helper.at(i - 1), helper.at(i - 2) + nums.at(i));
        }

        return helper.back();
    }
};
