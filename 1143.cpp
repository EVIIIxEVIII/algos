#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.size();
        int n = text2.size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    int prevDiag = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
                    dp[i][j] = prevDiag + 1;
                } else {
                    int top = i > 0 ? dp[i - 1][j] : 0;
                    int left = j > 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = std::max(top, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution solution;
    int ans = solution.longestCommonSubsequence("abcba", "abcbcba");
    printf("Ans: %d \n", ans);

    return 0;
}
