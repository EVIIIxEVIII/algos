#include <bits/stdc++.h>
#include <climits>
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
    int h, n;
    cin >> h >> n;

    vector<long long> a(n);
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // if that's another binary search problem I swear to God

    auto check = [&](long long moves) -> bool {
        __int128 damage = 0;
        for (int i = 0; i < n; ++i) {
            damage += a[i];
        }
        moves--;

        for (int i = 0; i < n; ++i) {
            damage += (__int128)a[i] * (moves / c[i]);
        }

        if (damage > LLONG_MAX) {
            return true;
        }

        return h <= damage;
    };

    long long l = 1, r = 4*1e10;
    // FFTT
    while (l < r) {
        long long m = l + (r - l) / 2;

        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << '\n';
}
