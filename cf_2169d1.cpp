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
    long long x, y, k;
    cin >> x >> y >> k;

    auto check = [&](long long val) {
        for (int i = 0; i < x; ++i) {
            val -= val / y;
        }
        return val;
    };


    long long l = 1;
    long long r = 1e12;

    while (l <= r) {
        long long m = l + (r - l) / 2;

        if (check(m) < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (l <= 1e12) {
        cout << l << '\n';
    } else {
        cout << -1 << '\n';
    }
}
