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
    long long l, r;
    cin >> l >> r;

    long long n = r - l + 1;

    cout << n * r << '\n';

    vector<uint32_t> ans(n, 0);
    for (uint32_t l = r; ; --l) {
        if (l == 0) break;
        if (ans[l] != 0) continue;

        uint32_t mask = ~l;
        uint32_t k = 31 - countl_zero(l);
        mask &= ((1u << k) - 1);

        ans[mask] = l;
        ans[l] = mask;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
