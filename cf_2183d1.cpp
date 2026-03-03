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
    // might be dsu with union by BFS layer and by parents
    int n; cin >> n;

    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // the absolute minimum number of sets is equal to the maximum breadth of the tree
    // so the number of moves is >= the layer with most nodes in the tree.
    // then probably if all the nodes in a layer have the same parent the answer is +1.

    vector<int> curr;
    curr.push_back(1);

    vector<int> vis(n+1, false);

    long long ans = 1;
    while (!curr.empty()) {
        vector<int> next;

        int max_added = 0;
        for (auto p : curr) {
            vis[p] = true;

            int curr_added = 0;
            for (auto v : graph[p]) {
                if (vis[v]) continue;

                next.push_back(v);
                curr_added++;
            }
            max_added = max(max_added, curr_added);
        }

        ans = max(size_t(ans), next.size() + (next.size() == max_added));
        curr = std::move(next);
    }

    cout << ans << '\n';
}
