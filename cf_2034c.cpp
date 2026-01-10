#include <bits/stdc++.h>
using namespace std;

void dfs(auto& graph) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // main idea: sometimes it is useful to flip the question, because that makes
        // solving the problem much easier.

        vector<vector<bool>> undef(n+2, vector<bool>(m+2, false));
        vector<vector<vector<pair<int, int>>>> graph(n+2, vector<vector<pair<int, int>>>(m+2));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                char dir; cin >> dir;

                int ni = i, nj = j;

                if (dir == 'U') {
                    ni--;
                } else if (dir == 'D') {
                    ni++;
                } else if (dir == 'R') {
                    nj++;
                } else if (dir == 'L') {
                    nj--;
                } else if (dir == '?') {
                    undef[i][j] = true;
                }

                graph[ni][nj].push_back({i, j});
            }
        }

        long long ans = 0;
        vector<vector<bool>> reachable(n+2, vector<bool>(m+2));
        auto dfs = [&](auto&& self, int i, int j) -> void {
            if (reachable[i][j]) return;
            reachable[i][j] = true;

            for (auto& [ni, nj] : graph[i][j]) {
                self(self, ni, nj);
            }
        };

        for (int j = 1; j <= m; ++j) {
            dfs(dfs, 0, j);
        }

        for (int j = 1; j <= m; ++j) {
            dfs(dfs, n+1, j);
        }

        for (int i = 1; i <= n; ++i) {
            dfs(dfs, i, 0);
        }

        for (int i = 1; i <= n; ++i) {
            dfs(dfs, i, m+1);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (undef[i][j]) {
                    if (
                        !reachable[i+1][j] ||
                        !reachable[i-1][j] ||
                        !reachable[i][j+1] ||
                        !reachable[i][j-1]
                    ) {
                        ans++;
                    }
                } else if (!reachable[i][j]) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
