#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

class Solution {
public:
    int numDecodings(std::string s) {
        std::vector<int> dpArray(s.size() + 1);

        if(s.at(0) == '0') return 0;
        if(s.size() == 1) return 1;

        dpArray.at(s.size()) = 1;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dpArray[i] = 0;
            } else {
                dpArray[i] = dpArray[i + 1];

                if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dpArray[i] += dpArray[i + 2];
                }
            }
        }

        return dpArray[0];
    }
};


int main() {
    auto solution = new Solution();

    int ans5 = solution->numDecodings("207");
    std::cout << "Final ans: " << ans5 << "\n";
}
