#include <string>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int maxL = 0;
        int maxR = 0;
        int maxI = 0;

        int i = 0;
        while (i < s.size()) {
            int l = 1;
            int r = 1;

            while(i + r < s.size() && s.at(i + r) == s.at(i)) {
                r++;
            }

            while (i - l > -1 && i + r < s.size()) {
                if (s.at(i - l) == s.at(i + r)) {
                    r++;
                    l++;
                } else break;
            }

            if ((r + l - 1) > (maxR + maxL - 1)) {
                maxR = r;
                maxL = l;
                maxI = i;
            }

            i += 1;
        }

        return s.substr(maxI - maxL + 1, maxR + maxL - 1);
    }
};


int main() {
    auto solution = new Solution();

    std::string ans = solution->longestPalindrome("cbbd");
    std::cout << ans << "\n";

    std::string ans2 = solution->longestPalindrome("babad");
    std::cout << ans2 << "\n";

    std::string ans3 = solution->longestPalindrome("bcccb");
    std::cout << ans3 << "\n";

    std::string ans4 = solution->longestPalindrome("ccc");
    std::cout << ans4 << "\n";

    std::string ans5 = solution->longestPalindrome("ccccc");
    std::cout << ans5 << "\n";

    delete solution;
}
