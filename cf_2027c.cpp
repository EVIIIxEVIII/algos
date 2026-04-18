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

    vector<long long> a(n+1);
    unordered_map<long long, vector<long long>> graph(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += i - 1; // probably valid
        if (i == 1) continue;

        // now we have a[i] = |a|, and then we can increase |a| by i - 1;
        // do we have graphs now?
        graph[a[i]].push_back(a[i] + i - 1);
    }

    long long ans = n;
    set<long long> vis;

    auto dfs = [&](auto&& self, long long len) -> long long {
        if (graph[len].empty() || !vis.insert(len).second) return len;
        for (long long child_len : graph[len]) {
            ans = max(ans, self(self, child_len));
        }
        return ans;
    };

    cout << dfs(dfs, n) << '\n';
}
