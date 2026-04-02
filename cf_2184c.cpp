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
    int n; cin >> n;
    int k; cin >> k;

    int rem = false;
    for (int i = 0; i < 31; ++i) {
        if ((n >> i) == k) {
            cout << i << '\n';
            return;
        }

        if (rem && (n >> i) + 1 == k) {
            cout << i << '\n';
            return;
        }

        rem |= (n >> i) & 1;
    }

    cout << -1 << '\n';
}
