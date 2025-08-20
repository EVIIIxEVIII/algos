#include <stdio.h>
#include <vector>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        int ans = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
                    dp[i][j - 1] = std::max(dp[i][j] + 1, dp[i][j - 1]);
                    ans = std::max(dp[i][j - 1], ans);
                }

                if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
                    dp[i][j + 1] = std::max(dp[i][j] + 1, dp[i][j + 1]);
                    ans = std::max(dp[i][j + 1], ans);
                }

                if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
                    dp[i - 1][j] = std::max(dp[i][j] + 1, dp[i - 1][j]);
                    ans = std::max(dp[i - 1][j], ans);
                }

                if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
                    dp[i + 1][j] = std::max(dp[i][j] + 1, dp[i + 1][j]);
                    ans = std::max(dp[i + 1][j], ans);
                }
            }
        }

        return ans;
    }
};


int main() {
    std::vector<std::vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution solution;
    int ans = solution.longestIncreasingPath(matrix);

    printf("Ans: %d \n", ans);
}
