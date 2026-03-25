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
    int n;
    cin >> n;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> tree(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    tree[1].push_back(1);

    // it probably makes sense to do the operation on the first split with respect to r, where we
    // take one subtree from the split and add it to another subtree.

    vector<long long> depth(n+1);
    vector<long long> score(n+1);
    vector<long long> sum(n+1);
    vector<long long> ans(n+1);

    auto dfs = [&](auto&& self, int v, int p) -> void {
        if (tree[v].size() == 1 && v != 1) {
            ans[v] = 0LL;
            depth[v] = 1LL;
            sum[v] = a[v];
            score[v] = 0LL;
            return;
        }

        long long max_d = 0;
        long long max_d_p = 0;

        long long total_score = 0;
        long long total_sum = 0;

        for (int u : tree[v]) {
            if (u == p) continue;

            self(self, u, v);
            total_score += score[u];
            total_sum += sum[u];

            if (depth[u] > max_d) {
                max_d_p = max_d;
                max_d = depth[u];
            } else if (depth[u] > max_d_p) {
                max_d_p = depth[u];
            }
        }

        total_score += total_sum;

        if (tree[v].size() == 2) {
            int only_child = tree[v][0] != p ? tree[v][0] : tree[v][1];
            ans[v] = ans[only_child] + sum[only_child];
        } else {
            long long answer = 0;
            for (int u : tree[v]) {
                if (u == p) continue;
                long long d = max_d;
                if (depth[u] == max_d) {
                    d = max_d_p;
                }

                answer = max({
                    answer,
                    total_score + sum[u]*d,
                    total_score - score[u] + ans[u]
                });
            }

            ans[v] = answer;
        }

        depth[v] = max_d + 1LL;
        score[v] = total_score;
        sum[v] = total_sum + a[v];
    };

    dfs(dfs, 1, 1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
