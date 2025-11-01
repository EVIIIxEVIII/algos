#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;

            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j] - '0';
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j]) break;
                vis[i][j] = 1;
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (!grid[i][j]) break;
                vis[i][j] = 1;
            }
        }

        bool ans = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j]) {
                    ans = false;
                    break;
                }
            }

            if (!ans) break;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
