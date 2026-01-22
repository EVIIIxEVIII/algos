#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // idea: work with the levels of the tree
        // basically at each node we ask: "Are there more than k descendents for node u?" if the answer is yes
        // we are guaranteed to have node u in S_r
        //
        // idea: we would need some kind of dp approach because any other approach would lead to O(n^2)
        //
        // idea: would be good to have some kind of a state array which would answer the question:
        // "if the edge u to v is incoming how many descendents does the node have?"
        // This would allow us to go through each node and ask this question for all of its edge, i.e
        // go through the nodes and ask "if this edge was incoming how many descendents would this node have?".
        // if the answer is >= k then we add +1 to the answer.
        // Each node can have exactly one incoming edge unless it is a root, if it is the root the answer is automatically 1.
        // Thus the answer is by default n;

        vector<vector<int>> g(n+1, vector<int>());

        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> subtree_sz(n+1, 1);
        auto dfs = [&](auto& dfs, int u, int p) -> void {
            for (auto& v : g[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                    subtree_sz[u] += subtree_sz[v];
                }
            }
        };

        dfs(dfs, 1, -1);

        long long ans = n;
        for (int i = 1; i <= n; ++i) {
            // the same idea as described above, but a little bit smarter.
            // here we only store the number of descendents at one single edge
            // and if the number of descendents at that edge is >= k then we can add +1 for
            // every edge outside of that subtree, i.e n - subtree[i]
            if (subtree_sz[i] >= k) {
                ans += n - subtree_sz[i];
            }

            // if the number of descendents on the other side of the tree is >= k then we can add +1
            // for every node inside that subtree
            if (n - subtree_sz[i] >= k) {
                ans += subtree_sz[i];
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
