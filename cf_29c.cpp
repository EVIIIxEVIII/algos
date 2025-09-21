#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        string a;
        a.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool ans = true;
        bool in_seg = a[0] == '1';
        int zeros = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == '0') zeros++;
            if (i == 0) continue;

            if (a[i] == '0' && a[i-1] == '0') in_seg = false;

            if (a[i] == '1' && a[i-1] == '1') {
                if (in_seg && zeros % 2) {
                    ans = false;
                    break;
                }

                zeros = 0;
                in_seg = true;
            }
        }

        if (in_seg && zeros % 2 == 1 && a[n - 1] == '1') {
            ans = false;
        }

        if (ans) cout << "YES" << '\n';
        else     cout << "NO" << '\n';

    }
    return 0;
}
