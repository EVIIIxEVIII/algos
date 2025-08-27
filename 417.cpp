#include <vector>

using namespace std;

class Solution {
    enum Ocean {
        NONE = 0,
        P = 1<<0, A = 1<<1, B = 0b11
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size();
        vector<vector<Ocean>> dp(m, vector<Ocean>(n, NONE));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        for (int i = 0; i < m; ++i) dfs(i, 0, heights, dp, vis, P);
        for (int j = 0; j < n; ++j) dfs(0, j, heights, dp, vis, P);

        std::fill(vis.begin(), vis.end(), vector<int>(n, 0));

        for (int i = 0; i < m; ++i) dfs(i, n-1, heights, dp, vis, A);
        for (int j = 0; j < n; ++j) dfs(m-1, j, heights, dp, vis, A);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == B) ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& h, vector<vector<Ocean>>& dp, vector<vector<int>>& vis, Ocean state) {
        int m = h.size(); int n = h[0].size();

        if (vis[i][j] == 1) return;
        vis[i][j] = 1;
        dp[i][j] = (Ocean)(dp[i][j] | state);

        if (j - 1 >= 0 && h[i][j-1] >= h[i][j]) {
            dfs(i, j-1, h, dp, vis, state);
        }

        if (j + 1 < n && h[i][j+1] >= h[i][j]) {
            dfs(i, j+1, h, dp, vis, state);
        }

        if (i - 1 >= 0 && h[i-1][j] >= h[i][j]) {
            dfs(i-1, j, h, dp, vis, state);
        }

        if (i + 1 < m && h[i+1][j] >= h[i][j]) {
            dfs(i+1, j, h, dp, vis, state);
        }
    }
};


int main() {

    Solution solution;

    vector<vector<int>> heights{{1,1},{1,1},{1,1}};

    solution.pacificAtlantic(heights);

}
