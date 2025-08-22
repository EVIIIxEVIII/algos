#include <vector>
#include <string>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {

        int n = word1.size(); int m = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) dp[i][n] = m - i;
        for (int j = n - 1; j >= 0; --j) dp[m][j] = n - j;


        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[j] == word2[i]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + std::min(std::min(dp[i+1][j], dp[i][j + 1]), dp[i+1][j+1]);
                }

            }
        }

        return dp[0][0];
    }
};
