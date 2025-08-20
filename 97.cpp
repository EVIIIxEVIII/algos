#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i - 1 < 0 && j - 1 < 0) {
                    dp[i][j] = true;
                    continue;
                }

                if (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }

            }
        }

        return dp[m][n];
    }
};
