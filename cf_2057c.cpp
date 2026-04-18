#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int l, r;
    cin >> l >> r;

    int base = 0;

    int h_r = 31;
    for (int i = 30; i >= 0; --i) {
        if (((l >> i) & 1) != ((r >> i) & 1)) {
            h_r = i;
            break;
        } else {
            base |= (((l >> i) & 1) << i);
        }
    }

    int a = base | (1 << h_r);
    int b = a - 1;
    int c = -1;

    for (int i = l; i <= r; ++i) {
        if (i != a && i != b) {
            c = i;
            break;
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';
}
