#include <stdio.h>
#include <vector>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int ans = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = std::max(ans, findLongestPath(i, j, matrix, dp));
            }
        }

        return ans;
    }

    int findLongestPath(int i, int j, std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= dp.size() || j >= dp[0].size()) {
            return 0;
        }

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int val = 1;

        if (i - 1 >= 0 && m[i - 1][j] > m[i][j]) {
            val = std::max(findLongestPath(i - 1, j, m, dp) + 1, val);
        }

        if (j - 1 >= 0 && m[i][j - 1] > m[i][j]) {
            val = std::max(findLongestPath(i, j - 1, m, dp) + 1, val);
        }

        if (i + 1 < m.size() && m[i + 1][j] > m[i][j]) {
            val = std::max(findLongestPath(i + 1, j, m, dp) + 1, val);
        }

        if (j + 1 < m[0].size() && m[i][j + 1] > m[i][j]) {
            val = std::max(findLongestPath(i, j + 1, m, dp) + 1, val);
        }

        dp[i][j] = val;

        return val;
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
