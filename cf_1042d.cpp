#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<vector<int>> tree(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        if (n == 2) {
            cout << 0 << '\n';
            continue;
        }

        // at each point in time we have to choose the node from the "perspective" which
        // there is the least amount of branches. A branch is an additional edge of a node.

        int totalBranches = 0;
        for (int i = 1; i <= n; ++i) {
            if (tree[i].size() > 2) {
                totalBranches += (tree[i].size() - 2);
            }
        }

        if (totalBranches == n-3) {
            cout << 0 << '\n'; // already minimum
            continue;
        }

        int ans = INT_MAX;

        //cout << totalBranches << '\n';
        for (int i = 1; i <= n; ++i) {
            int branchReduction = max(0, (int)tree[i].size() - 2);
            int val = totalBranches - branchReduction;

            int add = 0;
            for (int j = 0; j < (int)tree[i].size(); j++) {
                if (tree[tree[i][j]].size() >= 2) {
                    add++;
                }
            }

            ans = min(ans, val + (add >= 2 ? 2 : 1));
        }

        cout << ans << '\n';
    }
    return 0;
}
