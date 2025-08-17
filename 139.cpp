#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    std::string str = "leetcode";
    std::vector<std::string> wordDict{"leet","code"};

    Solution solution;
    bool val = solution.wordBreak(str, wordDict);

    printf("Res: %d\n", val);
}
