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
    int n, k;
    cin >> n >> k;

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    set<int> free;
    for (int i = 0; i < k; ++i) {
        int free_p;
        cin >> free_p;
        free.insert(free_p-1);
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int u; cin >> u;
            g[i].push_back(u-1);
        }
    }

    vector<long long> min_costs(n, -1);

    auto min_cost = [&](auto&& self, int p) -> long long {
        if (min_costs[p] != -1) {
            return min_costs[p];
        }

        if (free.contains(p)) {
            return 0;
        }

        if (g[p].empty()) {
            min_costs[p] = c[p];
            return c[p];
        }

        long long cost = 0;
        for (int v : g[p]) {
            cost += self(self, v);
        }

        min_costs[p] = min(cost, c[p]);
        return min_costs[p];
    };


    //cout << min_cost(min_cost, 0) << '\n';

    for (int i = 0; i < n; ++i) {
        cout << min_cost(min_cost, i) << ' ';
    }

    cout << '\n';
}
