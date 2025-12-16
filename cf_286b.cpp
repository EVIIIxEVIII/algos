#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> g(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    int q;
    cin >> q;
    vector<array<int, 2>> queries(q);

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        queries[i] = {u, v};
    }

    struct Frame {
        int node;
        int nextEdge;
        bool containsColor;
    };

    for (auto [u, v] : queries) {
        int ans = 0;
        vector<int> visiting(n+1, false);

        vector<Frame> stack;

        for (int currCol = 1; currCol <= m; ++currCol) {
            visiting[u] = true;
            stack.push_back({u, 0, true});

            bool connectsV = false;

            while (stack.size()) {
                auto& [vert, nextEdge, hasColor] = stack.back();

                if (vert == v && hasColor) {
                    connectsV = true;
                }

                if (nextEdge == g[vert].size()) {
                    visiting[vert] = false;
                    stack.pop_back();
                    continue;
                }

                auto [node, col] = g[vert][nextEdge++];
                bool newHasColor = hasColor && (col == currCol);

                if (!newHasColor) continue;
                if (visiting[node]) continue;

                visiting[node] = true;
                stack.push_back({node, 0, newHasColor});
            }

            ans += connectsV;
        }

        cout << ans << '\n';
    }

    return 0;
}
