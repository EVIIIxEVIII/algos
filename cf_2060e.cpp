#include <bits/stdc++.h>
using namespace std;

void solve();
int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }

    return parent[x];
}

void unite(vector<int>& parent, vector<int>& size, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);

    parent[b] = a;
    size[a] += size[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<int>> g_f(n+1);
    vector<vector<int>> g_g(n+1);

    vector<int> g_g_par(n+1);
    vector<int> g_g_sz(n+1, 1);
    for (int i = 1; i <= n; ++i) {
        g_g_par[i] = i;
    }

    vector<int> g_f_par(n+1);
    vector<int> g_f_sz(n+1, 1);
    for (int i = 1; i <= n; ++i) {
        g_f_par[i] = i;
    }

    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        g_f[u].push_back(v);
    }

    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        g_g[u].push_back(v);
        unite(g_g_par, g_g_sz, u, v);
    }

    long long ans = 0;

    for (int v = 1; v <= n; ++v) {
        long long local = 0;
        for (int u : g_f[v]) {
            if (find(g_g_par, u) != find(g_g_par, v)) {
                local++; // disconnect them
            } else {
                unite(g_f_par, g_f_sz, u, v);
            }
        }

        ans += local;
    }

    for (int v = 1; v <= n; ++v) {
        for (int u : g_g[v]) {
            if (find(g_f_par, u) != find(g_f_par, v)) {
                unite(g_f_par, g_f_sz, u, v);
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
