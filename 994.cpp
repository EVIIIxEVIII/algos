#include <vector>
#include <queue>
#include <array>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<array<int, 2>> bfs;
        int m = grid.size();
        int n = grid[0].size();

        bool containsOranges = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    bfs.push({i, j});
                }

                if (grid[i][j] == 1) {
                    containsOranges = true;
                }
            }
        }

        if (bfs.size() == 0 && !containsOranges) {
            return 0;
        }

        int ans = 0;
        while(bfs.size() > 0) {
            int queueSize = bfs.size();
            for (int k = 0; k < queueSize; ++k) {
                array<int, 2> cell = bfs.front();
                int i = cell[0]; int j = cell[1];

                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    bfs.push({i, j - 1});
                }

                if (j + 1 < n && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    bfs.push({i, j + 1});
                }

                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    bfs.push({i - 1, j});
                }

                if (i + 1 < m && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    bfs.push({i + 1, j});
                }

                bfs.pop();
            }

            ans++;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans-1;
    }
};
