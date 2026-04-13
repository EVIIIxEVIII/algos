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
    int x, y; cin >> x >> y;

    if ((x + y) % 2) {
        if (y == 0) {
            cout << "NO" << '\n';
            return;
        }
        y--;
    } else {
        if (x == 0) {
            cout << "NO" << '\n';
            return;
        }
        x--;
    }

    if (x > y || x < 0 || y < 0) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    if (x == 0 && y == 0) {
        return;
    }

    for (int i = 2; i <= y; ++i) {
        cout << 1 << ' ' << i << '\n';
    }

    for (int i = y+1; i <= (x + y+1); ++i) {
        cout << i-(y) << ' ' << i << '\n';
    }
}
