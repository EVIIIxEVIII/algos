#include <algorithm>
#include <vector>


class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int dpArray[2] = {cost[0], cost[1]};

        for (int i = 2; i < cost.size(); ++i) {
            int minIthCost = cost[i] + std::min(dpArray[0], dpArray[1]);
            dpArray[0] = dpArray[1];
            dpArray[1] = minIthCost;
        }

        return std::min(dpArray[0], dpArray[1]);
    }
};
