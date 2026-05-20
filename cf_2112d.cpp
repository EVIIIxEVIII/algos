#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
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
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // we can trivially achieve n - 1 good pairs by just cycling directions
    // on each level of the graph. So we need exactly one additional pair to fix the tree.
    //
    // One way we can do this is to have a subtree of size 3, then have the edges be from the left
    // leaf to the root and from the root to the right leaf. (wrong only the line one is correct)
    // If the subtree of size 3 is just a line, we can also obtain the additional pair by having the
    // eges be from the root to the first node and from the first node to the leaf.

    vector<pair<int, int>> ans;
    vector<bool> vis(n + 1, false);

    int r = -1;

    for (int i = 1; i <= n; ++i) {
        if ((int)g[i].size() == 2) {
            r = i;
            break;
        }
    }

    if (r == -1) {
        cout << "NO\n";
        return;
    }

    int u = g[r][0];
    int v = g[r][1];

    ans.push_back({u, r});
    ans.push_back({r, v});

    vis[r] = true;
    vis[u] = true;
    vis[v] = true;

    auto bfs = [&](int start, bool dir) {
        vector<int> current;
        current.push_back(start);

        while (!current.empty()) {
            vector<int> next;

            for (int x : current) {
                for (int y : g[x]) {
                    if (vis[y]) {
                        continue;
                    }

                    vis[y] = true;

                    if (dir) {
                        ans.push_back({x, y});
                    } else {
                        ans.push_back({y, x});
                    }

                    next.push_back(y);
                }
            }

            dir = !dir;
            current = std::move(next);
        }
    };

    bfs(u, true);
    bfs(v, false);

    cout << "YES\n";

    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }

}
