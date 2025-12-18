#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<int> l(q+1);
        vector<int> r(q+1);

        for (int i = 1; i <= q; ++i) {
            cin >> l[i];
            cin >> r[i];
        }

        vector<int> prefixOnes(n+1);
        prefixOnes[1] = a[1];
        for (int i = 2; i <= n; ++i) {
            prefixOnes[i] = prefixOnes[i-1] + (a[i] == 1);
        }

        vector<int> duplicatePrefix(n+1);
        duplicatePrefix[1] = 0;
        for (int i = 2; i <= n; ++i) {
            duplicatePrefix[i] = duplicatePrefix[i-1];
            if (a[i] == a[i-1]) {
                duplicatePrefix[i]++;
            }
        }

        for (int i = 1; i <= q; ++i) {
            if (
                (prefixOnes[r[i]] - prefixOnes[l[i] - 1]) % 3 != 0 ||
                ((r[i] - l[i] + 1) - (prefixOnes[r[i]] - prefixOnes[l[i] - 1])) % 3 != 0
            ) {
                cout << -1 << '\n';
                continue;
            }

            if (duplicatePrefix[r[i]] - duplicatePrefix[l[i]] != 0) {
                cout << (r[i] - l[i] + 1) / 3 << '\n';
            } else {
                cout << (r[i] - l[i] + 1) / 3 + 1 << '\n';
            }
        }

    }
    return 0;
}
