#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> deg(n+1, 0);
        vector<vector<int>> tree(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }

        if (n == 2) {
            cout << 0 << '\n';
            continue;
        }

        // at each point in time we have to choose the node from the "perspective" which
        // there is the least amount of branches. A branch is an additional edge of a node.

        int total = 0;

        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                total++;
            }
        }

        int best = 0;
        for (int i = 1; i <= n; ++i) {
            int localBest = 0;
            for (int j = 0; j < (int)tree[i].size(); ++j) {
                if (deg[tree[i][j]] == 1) {
                    localBest++;
                }
            }
            best = max(localBest, best);
        }

        cout << total - best << '\n';
    }
    return 0;
}
