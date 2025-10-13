#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<int> u(n-1);
        vector<int> v(n-1);
        vector<int> x(n-1);
        vector<int> y(n-1);

        for (int i = 0; i < n-1; ++i) {
            cin >> u[i];
            cin >> v[i];
            cin >> x[i];
            cin >> y[i];
        }

        vector<vector<int>> g(n+1, vector<int>(0));
        vector<int> indeg(n+1, 0);

        for (int i = 0; i < n-1; ++i) {
            if (x[i] >= y[i]) {
                g[u[i]].push_back(v[i]);
                indeg[v[i]]++;
            } else {
                g[v[i]].push_back(u[i]);
                indeg[u[i]]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> p(n+1);
        int label = n;
        while (!q.empty()) {
            int node = q.front(); q.pop();

            p[node] = label;
            label--;

            for (int i = 0; i < g[node].size(); ++i) {
                if (--indeg[g[node][i]] == 0) {
                    q.push(g[node][i]);
                }
            }
        }

        for (int i = 1; i < n+1; ++i) cout << p[i] << ' ';
        cout << '\n';
    }

    return 0;
}
