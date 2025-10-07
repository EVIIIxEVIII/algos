#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));


        for (int i = 0; i < n; ++i) {
            string in; cin >> in;

            for (int j = 0; j < m; ++j) {
                a[i][j] = in[j] - '0';
            }
        }

        int rows = 0;
        int cols = 0;

        for (int i = 0; i < n; ++i) {
            int val = a[i][0];
            for (int j = 1; j < m; ++j) {
                val ^= a[i][j];
            }

            if (val == 1) rows++;
        }

        for (int j = 0; j < m; ++j) {
            int val = a[0][j];
            for (int i = 1; i < n; ++i) {
                val ^= a[i][j];
            }

            if (val == 1) cols++;
        }

        cout << max(rows, cols) << '\n';
    }
    return 0;
}
