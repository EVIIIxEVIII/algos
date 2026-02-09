#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> prefix(n);
        prefix[0] = a[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = min(a[i], prefix[i-1]);
        }

        vector<int> suffix(n);
        suffix[n-1] = a[n-1];

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i+1], a[i]);
        }

        bool ans = true;
        for (int i = 0; i < n-1; ++i) {
            if (prefix[i] > suffix[i+1]) {
                ans = false;
                break;
            }
        }

        if (!ans) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        for (int i = 0; i < n-1; ++i) {
            if (suffix[i+1] > a[i]) {
                cout << suffix[i + 1] << ' ' << a[i] << '\n';
            } else {
                cout << prefix[i] << ' ' << suffix[i+1] << '\n';
            }
        }

    }

    return 0;
}
