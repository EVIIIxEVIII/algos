#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> rows(n);
        vector<int> cols(m);

        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x; cin >> x;

                if (x == 1) {
                    rows[i]++;
                    cols[i]++;
                    ones++;
                } else {
                    zeros++;
                }
            }
        }


        int change = 0;
        for (int i = 0; i < n; ++i) {
            if (rows[i] == 0 || rows[i] == n) {
                change++;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (cols[i] == 0 || cols[i] == m) {
                change++;
            }
        }


        cout << min({change, (n*m) - change}) << '\n';

    }
    return 0;
}
