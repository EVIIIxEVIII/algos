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
    long long p, q;
    cin >> p >> q;

    long long x = p + 2*q;
    long long target = 2*x + 1;

    long long div = 2;

    for (long long d = 1; d * d <= target; d++) {
        if (target % d != 0) continue;

        long long e = target / d;

        long long m = (d - 1) / 2;
        long long n = (e - 1) / 2;

        if (m > 0 && n > 0 && p >= abs(m - n)) {
            cout << m << ' ' << n << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
