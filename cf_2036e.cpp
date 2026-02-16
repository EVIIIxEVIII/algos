#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> grid(k, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> grid[j][i];
            if (i != 0) {
                grid[j][i] |= grid[j][i-1];
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;

        int lower = 0, higher = n-1;
        for (int j = 0; j < m; ++j) {
            long long r, c;
            char o;

            cin >> r >> o >> c;
            r--;

            // lower bound -> first where grid[r] >= c
            // upper bound -> first where grid[r] > c

            if (o == '<') {
                int bound = lower_bound(grid[r].begin(), grid[r].end(), c) - grid[r].begin();
                higher = min(bound - 1, higher);
            } else {
                int bound = upper_bound(grid[r].begin(), grid[r].end(), c) - grid[r].begin();
                lower = max(bound, lower);
            }
        }

        if (lower <= higher) {
            cout << lower + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
