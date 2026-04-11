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
    long long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    // 0 is non negative too
    long long num = 1;
    long long ans = 0;

    // 2 1 1 3 3
    while (num <= 1e9) {
        long long y_min = (l2 + num - 1) / num;
        long long y_max = r2 / num;

        long long range_min = max(l1, y_min);
        long long range_max = min(r1, y_max);

        ans += max(range_max - range_min + 1, 0LL);
        num *= k;
    }

    cout << ans  << '\n';
}
