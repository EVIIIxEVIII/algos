#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int idx = -1;
        int tank = 0;

        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                idx = i+1;
                tank = 0;
            }
        }

        if (sum < 0) {
            return -1;
        }

        return idx;
    }
};
