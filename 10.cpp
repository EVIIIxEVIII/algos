#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = p.size(); int n = s.size();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 2; i <= m; ++i) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 2][0];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {

                if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];

                    if (p[i - 2] == s[j - 1] || p[i - 2] == '.') {
                        dp[i][j] = dp[i][j - 1] || dp[i][j];
                    }
                } else {
                    if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
