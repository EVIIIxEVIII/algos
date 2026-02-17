#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> g(k, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> g[j][i];

            if (i != 0) {
                g[j][i] |= g[j][i-1];
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;

        int lower = 0, higher = n - 1;
        for (int j = 0; j < m; ++j) {
            int r, c;
            char o;

            cin >> r >> o >> c;
            r--;

            if (o == '>') {
                int bound = upper_bound(g[r].begin(), g[r].end(), c) - g[r].begin();
                lower = max(lower, bound);
            } else {
                int bound = lower_bound(g[r].begin(), g[r].end(), c) - g[r].begin();
                bound--;
                higher = min(bound, higher);
            }
        }

        if (lower <= higher) {
            cout << lower+1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }


    return 0;
}
