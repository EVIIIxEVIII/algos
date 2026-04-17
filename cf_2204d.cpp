#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n+1, false);
    vector<int> coloring(n+1, 0);

    auto dfs = [&](auto&& self, int u, int color, int& c1, int& c2) {
        if (vis[u]) {
            return (color == coloring[u] ? 0 : -1);
        }

        vis[u] = true;
        coloring[u] = color;

        if (color == 1) c1++;
        else c2++;

        int count = 1;
        bool ok = true;
        for (int v : g[u]) {
            int child_count = self(self, v, 3 - color, c1, c2);
            if (child_count == -1) {
                ok = false;
            }
            count += child_count;
        }

        return ok ? count : -1;
    };

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int c1 = 0, c2 = 0;
            int count = dfs(dfs, i, 1, c1, c2);
            if (count != -1) {
                ans += max(c1, c2);
            }
        }
    }

    cout << ans << '\n';
}
