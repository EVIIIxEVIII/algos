#include <vector>
#include <stdio.h>


class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> board(m, std::vector<int>(n, 0));

        board[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + 1 < n) {
                   board[i][j + 1] += board[i][j];
                }

                if (i + 1 < m) {
                    board[i + 1][j] += board[i][j];
                }
            }
        }


        return board[m - 1][n - 1];
    }
};

int main() {

    Solution solution;
    int res = solution.uniquePaths(3, 7);

    printf("Res %d \n", res);

    return 0;
}
