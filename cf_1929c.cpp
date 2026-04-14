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
    int k, x, a;
    cin >> k >> x >> a;

    long long max_loss = 0;

    for (int i = 0; i <= x; ++i) {
        long long bet = max_loss / (k - 1) + 1;
        max_loss += bet;
        if (max_loss > a) break;
    }

    if (max_loss > a) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}
