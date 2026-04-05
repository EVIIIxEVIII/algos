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

constexpr long long mod = 676767677;
void solve() {
    long long n, m; cin >> n >> m;
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (b[0] != 0 && b[1] >= b[0]) {
        cout << 0 << '\n';
        return;
    }

    if (b[n-1] != 0 && b[n-2] >= b[n-1]) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i < n-1; ++i) {
        if (b[i-1] >= b[i] && b[i+1] >= b[i] && b[i] != 0) {
            cout << 0 << '\n';
            return;
        }
    }

    vector<long long> cnt(m);
    for (int i = 0; i < n; ++i) {
        cnt[b[i]]++;
    }

    vector<long long> prefix(m+1);
    prefix[0] = 0;
    for (int i = 1; i < m; ++i) {
        prefix[i] = prefix[i-1] + cnt[i-1];
    }

    long long ans = 1;
    for (int i = 1; i < m; ++i) {
        ans = (ans + (cnt[i] * min(n-1, prefix[i]) % mod)) % mod;
    }

    cout << ans << '\n';
}
