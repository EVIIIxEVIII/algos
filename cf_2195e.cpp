#include <bits/stdc++.h>
using namespace std;

void solve();
constexpr long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> tree(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >>tree[i].first;
        cin >>tree[i].second;
    }

    vector<long long> subtree(n+1);
    auto dfs = [&](auto&& self, int node) -> int {
        if (tree[node].first == 0 && tree[node].second == 0) {
            subtree[node] = 0;
            return 1;
        }

        subtree[node] += self(self, tree[node].first);
        subtree[node] += self(self, tree[node].second);
        return subtree[node] + 1;
    };

    dfs(dfs, 1);

    vector<int> ans_vec(n+1);
    auto dfs2 = [&](auto&& self, int node, long long ans) {
        if (node == 0) return;
        ans = (ans + 1 + (2LL * subtree[node] % mod)) % mod;
        ans_vec[node] = ans;

        self(self, tree[node].first, ans);
        self(self, tree[node].second, ans);
    };

    dfs2(dfs2, 1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans_vec[i] << ' ';
    }

    cout << '\n';
}
