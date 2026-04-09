#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,long long>>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;

        graph[u].push_back({ v, l });
        graph[v].push_back({ u, l });
    }

    set<int> s;
    for (int i = 0; i < k; ++i) {
        int n; cin >> n;
        s.insert(n);
    }

    long long ans = INT_MAX;
    for (int u = 1; u <= n; ++u) {
        if (s.contains(u)) continue;
        for (auto [v, l] : graph[u]) {
            if (s.contains(v)) {
                ans = min(l, ans);
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
