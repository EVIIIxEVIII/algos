#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        bool ans = a[n-1] == b[n-1];

        for (int i = 0; i < n-1; ++i) {
            if (a[i] == b[i]) { continue; }
            if ((a[i] ^ a[i+1]) == b[i]) {
                a[i] = b[i];
            }
        }

        for (int i = n-2; i >= 0; --i) {
            if (a[i] == b[i]) { continue; }

            if ((a[i] ^ a[i+1]) == b[i]) {
                a[i] = b[i];
            } else {
                ans = false;
            }
        }

        if (!ans) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
    }
    return 0;
}
