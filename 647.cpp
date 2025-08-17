#include <string>
#include <iostream>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = s.size();

        int i = 0;
        while (i < s.size()) {
            int l = 1;
            int r = 1;

            while(i + r < s.size() && s.at(i + r) == s.at(i)) {
                count++;
                r++;
            }

            while (i - l > -1 && i + r < s.size()) {
                if (s.at(i - l) == s.at(i + r)) {
                    count++;
                    r++;
                    l++;
                } else break;
            }

            i += 1;
        }

        return count;
    }
};


int main() {
    auto solution = new Solution();

    int ans = solution->countSubstrings("cbbd");
    std::cout << ans << "\n";

    int ans2 = solution->countSubstrings("babad");
    std::cout << ans2 << "\n";

    int ans3 = solution->countSubstrings("bcccb");
    std::cout << ans3 << "\n";

    int ans4 = solution->countSubstrings("ccc");
    std::cout << ans4 << "\n";

    int ans5 = solution->countSubstrings("ccccc");
    std::cout << ans5 << "\n";

    int ans6 = solution->countSubstrings("aaa");
    std::cout << ans6 << "\n";

    int ans7 = solution->countSubstrings("abc");
    std::cout << ans7 << "\n";

    delete solution;
}

