#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); int n = board[0].size();

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, dp);
            if (board[i][n-1] == 'O') dfs(i, n-1, board, dp);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, dp);
            if (board[m-1][j] == 'O') dfs(m-1, j, board, dp);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!dp[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& dp) {
        int m = board.size(); int n = board[0].size();

        dp[i][j] = true;

        if (i-1 >= 0 && board[i-1][j] == 'O' && !dp[i-1][j]) {
            dfs(i-1, j, board, dp);
        }

        if (i+1 < m && board[i+1][j] == 'O' && !dp[i+1][j]) {
            dfs(i+1, j, board, dp);
        }

        if (j-1 >= 0 && board[i][j-1] == 'O' && !dp[i][j-1]) {
            dfs(i, j-1, board, dp);
        }

        if (j+1 < n && board[i][j+1] == 'O' && !dp[i][j+1]) {
            dfs(i, j+1, board, dp);
        }
    }
};



