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

constexpr long long mod = 1e9 + 7;
long long pow_(long long a, long long b) {
    a %= mod;
    long long ans = 1;

    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
};

void solve() {
    long long n; cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += a[i];
    }

    long long P = 0;
    for (int i = 0; i < n; ++i) {
        total -= a[i];
        P = (P + (__int128)a[i] * total % mod) % mod;
    }

    long long Q = (n - 1LL) * n / 2LL;
    long long Q1 = pow_(Q, mod-2);

    cout << P * Q1 % mod << '\n';
}
