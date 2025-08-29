#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int ans = 0;
        int i = 0;
        while (i < nums.size()) {
            int localMax = nums[i];
            int nextJump = 0;
            int nextJumpIdx = -1;

            for (int j = 1; j <= localMax; ++j) {
                nextJump--;
                if (i+j >= nums.size() - 1) {
                    return ans+1;
                } else if (nums[i+j] >= nextJump) {
                    nextJump = nums[i+j];
                    nextJumpIdx = i+j;
                }
            }

            ++ans;
            i = nextJumpIdx;
        }

        return ans;
    }
};
