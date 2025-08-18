#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::vector<int> hold(prices.size(), 0);
        hold[0] = -1 * prices[0];

        std::vector<int> rest(prices.size(), 0);
        std::vector<int> sell(prices.size(), 0);

        for (int i = 1; i < prices.size(); ++i) {
            hold[i] = std::max(hold[i - 1], rest[i - 1] - prices[i]);
            sell[i] = prices[i] + hold[i - 1];
            rest[i] = std::max(sell[i - 1], rest[i - 1]);
        }

        int ans = prices.size() - 1;
        return std::max(std::max(sell[ans], hold[ans]), rest[ans]);
    }
};
