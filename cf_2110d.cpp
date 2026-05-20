#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    vector<int> b(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    // another graph problem? proly with some DP
    // and some b-search involved mb?
    vector<vector<pair<int,long long>>> g(n+1);

    for (int i = 0; i < m; ++i) {
        long long s, t, w;
        cin >> s >> t >> w;
        g[s].push_back({t, w});
    }

    auto check = [&](long long bt) -> bool {
        vector<long long> best(n + 1, -1);

        auto dfs = [&](auto&& self, int v, long long current) {
            current = min(bt, current + b[v]);

            if (current <= best[v]) {
                return false;
            }

            best[v] = current;
            if (v == n) {
                return true;
            }

            for (auto& [u, w] : g[v]) {
                if (current >= w && self(self, u, current)) {
                    return true;
                }
            }

            return false;
        };

        return dfs(dfs, 1, 0);
    };


    long long l = 0, r = 1e9;

    while (l < r) {
        long long m = l + (r - l) / 2;

        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << (check(l) ? l : -1) << '\n';
}
