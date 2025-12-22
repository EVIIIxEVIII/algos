#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;
    while (t--) {

        int64_t n;
        cin >> n;
        vector<int64_t> dangers(n+1, 0);

        for (int64_t i = 1; i <= n; ++i) {
            cin >> dangers[i];
        }

        vector<vector<int64_t>> tree(n+1, vector<int64_t>());

        for (int64_t i = 0; i < n-1; ++i) {
            int64_t u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // idea is simple: reverse the idea by going from node 1 to all the other nodes by do
        // a dfs and use DP to track the optimal score for each node

        vector<int64_t> ans(n+1, 0);
        vector<int64_t> mins(n+1, 0);
        struct Frame {
            int64_t node;
            int64_t parent;
            int64_t childId;
        };

        vector<int64_t> visiting(n+1, false);
        vector<Frame> stack;
        stack.push_back({1, 0, 0});
        visiting[1] = true;

        while (!stack.empty()) {
            auto& [node, parent, childId] = stack.back();

            if (childId == 0) {
                ans[node] = max(dangers[node], dangers[node] - mins[parent]);
                mins[node] = min(dangers[node], dangers[node] - ans[parent]);
            }

            if (childId == tree[node].size()) {
                visiting[node] = false;
                stack.pop_back();
                continue;
            }

            int64_t child = tree[node][childId++];
            if (visiting[child]) continue;

            visiting[child] = true;
            stack.push_back({ child, node, 0 });
        }

        for (int64_t i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
