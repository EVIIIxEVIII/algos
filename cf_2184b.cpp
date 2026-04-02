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
    int s, k, m;
    cin >> s >> k >> m;

    if (s <= k) {
        cout << max(0, s - (m%k)) << '\n';
        return;
    }

    if ((m / k) % 2 == 1) {
        cout << max(0, k - (m%k)) << '\n';
    } else {
        cout << max(0, s - (m%k)) << '\n';
    }
}
