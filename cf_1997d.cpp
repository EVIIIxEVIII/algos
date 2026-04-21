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
    int n; cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> graph(n+1);
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        graph[p].push_back(i);
        //graph[i].push_back(p);
    }

    auto dfs = [&](auto&& self, int v) -> int {
        if (graph[v].empty()) {
            return a[v];
        }

        int min_subtree = INT_MAX;
        for (int u : graph[v]) {
            min_subtree = min(min_subtree, self(self, u));
        }

        if (a[v] < min_subtree) {
            min_subtree = min((a[v] + min_subtree) / 2, min_subtree);
        }

        return min_subtree;
    };

    int ans = INT_MAX;

    for (int u : graph[1]) {
        ans = min(ans, dfs(dfs, u));
    }

    cout << a[1] + ans << '\n';
}
