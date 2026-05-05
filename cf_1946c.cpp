#include <bits/stdc++.h>
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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n+1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto check = [&](int x) -> bool {
        int times = 0;
        auto dfs = [&](auto&& self, int v, int p) -> long long {
            long long subtree_sz = 1;
            for (int u : g[v]) {
                if (u == p) continue;
                subtree_sz += self(self, u, v);
            }

            if (subtree_sz >= x) {
                times++;
                return 0;
            }

            return subtree_sz;
        };

        dfs(dfs, 1, 0);
        return times >= k + 1;
    };

    //TTFF
    int l = 1;
    int r = n;

    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}
