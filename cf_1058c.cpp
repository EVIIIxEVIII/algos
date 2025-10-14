#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n == 0) {
            cout << "YES" << '\n';
            continue;
        }

        int r = __builtin_ctz(n);
        int l = 31 - __builtin_clz(n);

        int reverse = 0;
        for (int i = l, j = r; i >= r; --i, ++j) {
            reverse |= ((n >> i) & 1) << j;
        }

        int mid = (l + r) / 2;
        if (reverse != n || ((l - r + 1) % 2 && (n >> mid) & 1)) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }

    }
    return 0;
}
