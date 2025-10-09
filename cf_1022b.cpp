#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x; cin >> x;

        int setBits = 0;

        for (int i = 0; i < 32; ++i) {
            setBits += (x >> i) & 1;
        }

        if (setBits >= n) {
            cout << x << '\n';
            continue;
        }

        if (x == 0 && n == 1) {
            cout << -1 << '\n';
            continue;
        }

        if (x == 0 && n % 2) {
            cout << 1 + 2 + 3 + (n - 3) << '\n';
            continue;
        }

        if (x == 1 && n % 2 == 0) {
            cout << 5 + (n - 2) << '\n';
            continue;
        }

        int ans = x + (n - setBits) + ((n - setBits) % 2 == 0 ? 0 : 1);

        cout << ans << '\n';
    }

    return 0;
}
