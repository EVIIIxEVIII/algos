#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (maxJump == 0) {
                return false;
            } else {
                maxJump--;
                if (nums[i] > maxJump) {
                    maxJump = nums[i];
                }
            }
        }

        return true;
    }
};
