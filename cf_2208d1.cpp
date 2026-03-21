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

    vector<vector<int>> g(n+1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;

        for (int j = 1; j <= n; ++j) {
            if (row[j-1] == '1') {
                g[i].push_back(j);
            }
        }
    }

    // if there exits a node A that can reach a node B, then node A can reach all the nodes node B can reach.
    // so the configuration must satisfy the property that g[B] must be a subset of g[A] where there exists an edge from A to B.

    // maybe we can start from the leaf nodes? if we assume that there always exists at least one node X such that |g[X]| = 1,
    // we can start from this node, then go bottom up. the indexistance of X, s.t |g[X]| = 1, would imply a cycle in the graph
    // which would make the graph invalid by default.

    // let L be the set of all nodes l such that |g[l]| = 1. There must exist at least 1 node l_2 such that g[l_2] \ l_2 is a
    // subset of L, in other words the nodes l are a part of the first layer of the DAG and the nodes in the set L2 the second
    // layer of the DAG. Thus we can conclude that there is a direct reachability from the nodes in L2 to the nodes in L1.
    // By induction we can traverse the DAG bottom up from L1 to Ln;

    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end(), [&](int u, int v) {
            return g[u].size() > g[v].size();
        });
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        vector<bool> contains(n+1, false);
        for (auto& u : g[i]) {
            contains[u] = true;
        }

        int sz = g[i].size();
        int j = 0;
        int seen_vals = 0;
        int edge_idx = 0;

        while (sz - seen_vals != 1 && j < sz) {
            int edge = 0;

            for (int j = edge_idx; j < g[i].size(); ++j) {
                int v = g[i][j];
                if (v == i || !contains[v]) continue;
                edge = v;
                edge_idx = j + 1;
                break;
            }

            ans.push_back({ i, edge });
            for (auto& v : g[edge]) {
                if (contains[v] && v != i) {
                    contains[v] = false;
                    seen_vals++;
                } else {
                    cout << "no" << '\n';
                    return;
                }
            }

            ++j;
        }
    }

    if (ans.size() != n - 1) {
        cout << "no" << '\n';
        return;
    }

    vector<vector<int>> tree(n+1, vector<int>());
    for (auto [s, d] : ans) {
        tree[s].push_back(d);
        tree[d].push_back(s);
    }

    vector<bool> visited(n+1, false);
    auto dfs = [&](auto&& self, int u) -> void {
        if (visited[u]) return;

        visited[u] = true;
        for (auto& v : tree[u]) {
            self(self, v);
        }
    };

    dfs(dfs, 1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "yes" << '\n';
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}
