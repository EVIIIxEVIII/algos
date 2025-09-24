#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<set<int>> map(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;

            map[u].insert(v);
            map[v].insert(u);
        }

        vector<vector<int>> scores(n+1);
        for (int i = 1; i <= n; ++i) {

        }

    }
    return 0;
}
