#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> first(2);
        std::vector<int> second(2);

        if(nums.size() == 1) return nums.at(0);
        if(nums.size() == 2) return std::max(nums.at(0), nums.at(1));

        first.at(0) = nums.at(0);
        first.at(1) = std::max(nums.at(0), nums.at(1));

        second.at(0) = nums.at(1);
        second.at(1) = std::max(nums.at(1), nums.at(2));

        for (int i = 2; i < nums.size() - 1; ++i) {
            int ansFirst = std::max(first.at(1), first.at(0) + nums.at(i));
            first.at(0) = first.at(1);
            first.at(1) = ansFirst;

            int ansSecond = std::max(second.at(1), second.at(0) + nums.at(i+1));
            second.at(0) = second.at(1);
            second.at(1) = ansSecond;
        }

        return std::max(second.at(1), first.at(1));
    }
};
