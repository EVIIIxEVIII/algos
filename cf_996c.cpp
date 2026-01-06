#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string path;
        cin >> path;

        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int gi = 0, gj = 0;

        for (auto c : path) {
            if (c == 'R') {
                long long sum = 0;

                for (int i = 0; i < n; ++i) {
                    sum += grid[i][gj];
                }

                grid[gi][gj] = -sum;
                gj++;
            } else if (c == 'D') {
                long long sum = 0;

                for (int j = 0; j < m; ++j) {
                    sum += grid[gi][j];
                }

                grid[gi][gj] = -sum;
                gi++;
            }
        }

        long long last_sum = 0;

        for (int j = 0; j < m; ++j) {
            last_sum += grid[n-1][j];
        }

        grid[n-1][m-1] = -last_sum;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
