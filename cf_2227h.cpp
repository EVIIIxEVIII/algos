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
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> cnt(n+1);
    long long ans = 0;

    auto dfs = [&](auto&& self, int u, int p) -> void {
        bool is_leaf = true;
        for (int v : g[u]) {
            if (v == p) {
                continue;
            }

            is_leaf = false;
            self(self, v, u);
            cnt[u] += cnt[v];

            if (cnt[v] % 2) {
                ans++;
            }
        }

        if (is_leaf) {
            cnt[u] = 1;
        }
    };

    int root = 1;
    for (int r = 1; r <= n; ++r) {
        if (g[r].size() > 1) {
            root = r;
            break;
        }
    }

    dfs(dfs, root, 0);
    vector<int> dp(n+1, -1e9);
    auto dfs2 = [&](auto&& self, int u, int p) -> void {
        bool is_leaf = true;

        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            is_leaf = false;
            dp[u] = max(dp[u], dp[v] + (cnt[v] % 2 ? 1 : -1));
        }

        if (is_leaf) {
            dp[u] = 0;
        }
    };

    if (cnt[root] % 2) {
        dfs2(dfs2, root, 0);
        ans -= dp[root];
    }

    cout << ans << '\n';
}
