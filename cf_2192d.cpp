#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        // idea: precompute the sum of a_u * d(r, u) for each node, then for each subtree with root r we need to find
        // the node that is not a part of that subtree but which is the most distant from the root.

        // idea: do a dfs and each node will return a tuple of 3 elements: [sum, weighted_sum, max_depth]
        // where sum is the sum of a[i] is all of its children and weighted_sum is the total weighted sum including
        // the depth of each child.

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

        struct Res {
            long long sum;
            long long weighted_sum;
            long long max_depth;
        };

        vector<long long> sum(n + 1);
        vector<long long> w_sum(n + 1);
        vector<long long> depth(n + 1);
        vector<long long> best_child_gain(n + 1);

        vector<long long> ans_vec(n+1);
        auto dfs = [&](auto&& self, int u, int p) -> Res {
            Res res = { a[u], 0, 0 };
            long long max_depth = 0;
            long long max_depth_prev = 0;
            int max_depth_child = 0;

            best_child_gain[u] = 0;
            for (auto& v : tree[u]) {
                if (v == p) continue;

                auto [ s, ws, d ] = self(self, v, u);
                best_child_gain[u] = max(best_child_gain[u], best_child_gain[v]);

                if (d + 1 > max_depth) {
                    max_depth_prev = max_depth;
                    max_depth = d + 1;
                    max_depth_child = v;
                }

                res.sum += s;
                res.weighted_sum += ws + s;
                res.max_depth = max(res.max_depth, d + 1);
            }

            long long gain = 0;
            for (auto& v : tree[u]) {
                if (v == p) continue;
                long long D = (v == max_depth_child ? max_depth_prev : max_depth);
                gain = max(gain, D * sum[v]);
                best_child_gain[u] = max(best_child_gain[u], gain);
            }

            ans_vec[u] = res.weighted_sum + best_child_gain[u];

            sum[u] = res.sum;
            w_sum[u] = res.weighted_sum;
            depth[u] = res.max_depth;

            return res;
        };

        dfs(dfs, 1, 1);

        for (int i = 1; i <= n; ++i) {
            cout << ans_vec[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
