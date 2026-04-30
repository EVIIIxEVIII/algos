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
    int x, y;
    cin >> x >> y;

    if (x % 2 && y % 2) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}
