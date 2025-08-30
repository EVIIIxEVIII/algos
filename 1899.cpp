#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        array<int, 3> ans = {0, 0, 0};

        for (int i = 0; i < triplets.size(); ++i) {
            vector<int>& triplet = triplets[i];
            if (target[0] >= triplet[0] && target[1] >= triplet[1] && target[2] >= triplet[2]) {
                ans[0] = std::max(ans[0], triplet[0]);
                ans[1] = std::max(ans[1], triplet[1]);
                ans[2] = std::max(ans[2], triplet[2]);
            }
        }

        return
            ans[0] == target[0] &&
            ans[1] == target[1] &&
            ans[2] == target[2];
    }
};
