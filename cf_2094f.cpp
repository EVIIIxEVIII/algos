#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int cpn = (n*m) / k;

        int count = k;
        int middle = (k + 1) / 2;


        if (m % k != 0) {
            for (int i = 0; i < cpn; ++i) {
                for (int j = 1; j <= k; ++j) {
                    cout << j << ' ';
                    if (((k*i)+j) % m == 0) cout << '\n';
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                int shift = i % k;
                for (int j = 0; j < m; ++j) {
                    cout << (j + shift) % k + 1 << ' ';
                }

                cout << '\n';
            }
        }

    }
    return 0;
}
