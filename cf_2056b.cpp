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

    vector<unordered_set<int>> graph(n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char edge; cin >> edge;
            if (edge == '1') {
                graph[i].insert(j);
            }
        }
    }

    vector<int> ans(n);
    for (int v = 1; v <= n; ++v) {
        int idx = 0;

        for (int u = 1; u < v; ++u) {
            if (graph[v].contains(u)) {
                idx++;
            }
        }

        for (int u = v+1; u <= n; ++u) {
            if (!graph[v].contains(u)) {
                idx++;
            }
        }
        ans[idx] = v;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
