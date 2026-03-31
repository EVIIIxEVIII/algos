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
constexpr int troll = 676767677;

void solve() {
    int x, y;
    cin >> x >> y;

    long long ans = 0;
    int count = abs(x - y);

    for (long long i = 1; i * i <= count; ++i) {
        if (count % i == 0) {
            ans += 1 + (count / i != i);
        }
    }

    cout << max(1LL, ans % troll) << '\n';
    for (int i = 0; i < y; ++i) {
        cout << -1 << ' ';
    }

    for (int i = 0; i < x; ++i) {
        cout << 1 << ' ';
    }

    cout << '\n';
}
