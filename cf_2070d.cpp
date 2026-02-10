#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<int> p(n-1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> p[i];
        }

        vector<vector<int>> adj(n+1, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            adj[p[i]].push_back(i+2);
        }

        vector<long long> dp(n+1, 0);
        vector<long long> layer;

        dp[1] = 1;
        layer.push_back(1);

        vector<int> bfs;
        for (auto& v : adj[1]) {
            bfs.push_back(v);
            dp[v] = layer[0];
        }

        layer.push_back(adj[1].size());

        int l = 2;
        while(!bfs.empty()) {
            vector<int> next;

            for (auto& u : bfs) {
                for (auto& v : adj[u]) {
                    // arithmetically layer[l-1] cannot be smaller than dp[u] but because
                    // we use modulo arithmetic, it can be smaller, so we need to wrap it correctly
                    // % in C++ preserves the sign, but we don't want that, so we add the prime to it
                    dp[v] = (layer[l - 1] - dp[u] + 998244353) % 998244353;
                    next.push_back(v);
                }
            }

            if (next.size()) {
                layer.push_back(0);

                for (auto& v : next) {
                    layer[l] = (layer[l] + dp[v]) % 998244353;
                }
            }

            bfs = std::move(next);
            l++;
        }

        long long ans = 0;

        for (auto& cnt : dp) {
            ans = (ans + cnt) % 998244353;
        }

        cout << ans << '\n';
    }
    return 0;
}
