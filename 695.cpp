#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ans = std::max(dfs(i, j, grid), ans);
            }
        }

        return ans;
    }

    int dfs(int i, int j, std::vector<std::vector<int>>& m) {
        if (i < 0 || j < 0 || i >= m.size() || j >= m[0].size() || m[i][j] == 0) {
            return 0;
        }

        m[i][j] = 0;
        int ret = 1+dfs(i+1,j,m)+dfs(i,j+1,m)+dfs(i-1,j,m)+dfs(i,j-1,m);
        return ret;
    }
};
