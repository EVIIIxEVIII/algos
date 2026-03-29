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
    long long n, x;
    cin >> n >> x;

    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<long long> jumps(n);
    for (int i = 0; i < n; ++i) {
        x -= (b[i] - 1LL) * a[i];
        jumps[i] = 1LL * a[i] * b[i] - c[i];
    }

    sort(jumps.begin(), jumps.end(), greater<long long>());
    if (x <= 0) {
        cout << 0 << '\n'; return;
    }

    if (jumps[0] <= 0) {
        cout << -1 << '\n'; return;
    }

    cout << (x + jumps[0]-1) / jumps[0] << '\n';
}
