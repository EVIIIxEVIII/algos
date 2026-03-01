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
    long long s, m;
    cin >> s >> m;

    if (__builtin_ctzll(s) < __builtin_ctzll(m)) {
        cout << -1 << '\n';
        return;
    }

    long long S = 0;
    long long M = 0;
    long long ans = 0;

    for (int i = 0; i < 61; ++i) {
        M += ((m >> i) & 1LL) * (1LL << i);
        S += ((s >> i) & 1LL) * (1LL << i);

        if (S > 0) {
            ans = max(ans, (S + (M - 1)) / M);
        }
    }

    cout << ans << '\n';
}
