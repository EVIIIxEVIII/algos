#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int globalGold = 0;
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int isG = (grid[i][j] == 'g');
                globalGold += isG;

                if (j == 0) {
                    prefixSum[i][j] = isG;
                } else {
                    prefixSum[i][j] = prefixSum[i][j-1] + isG;
                }
            }
        }

        long long globalMin = 1e18;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '.') continue;

                int sum = 0;

                int leftMostCol = max(0, j-(k-1));
                int rightMostCol = min(m-1, j+(k-1));

                int topMostRow = max(0, i-(k-1));
                int bottomMostRow = min(n-1, i+(k-1));

                for (int t = topMostRow; t <= bottomMostRow; ++t) {
                    sum += prefixSum[t][rightMostCol] - (leftMostCol ? prefixSum[t][leftMostCol-1] : 0);
                }

                globalMin = min((long long)sum, globalMin);
            }
        }

        cout << globalGold - globalMin << '\n';
    }
    return 0;
}
