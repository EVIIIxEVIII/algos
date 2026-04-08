#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 998244353;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

long long pow_(long long a, long long b) {
    long long ans = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            ans = (__int128)ans * a % mod;
        }

        b >>= 1;
        a = (__int128)a * a % mod;
    }

    return ans % mod;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<pair<int,int>> pref_a(n);
    vector<pair<int,int>> pref_b(n);

    pref_a[0] = { a[0], 0 };
    pref_b[0] = { b[0], 0 };

    for (int i = 1; i < n; ++i) {
        pref_a[i] = max(pref_a[i-1], { a[i], i });
        pref_b[i] = max(pref_b[i-1], { b[i], i });
    }

    vector<long long> r(n);
    for (int i = 0; i < n; ++i) {
        long long power1;
        long long power2;

        if (pref_a[i].first > pref_b[i].first) {
            auto [val, pos] = pref_a[i];
            power1 = val;
            power2 = b[i-pos];
        } else if (pref_b[i].first > pref_a[i].first) {
            auto [val, pos] = pref_b[i];
            power1 = val;
            power2 = a[i-pos];
        } else {
            auto [val_a, pos_a] = pref_a[i];
            auto [val_b, pos_b] = pref_b[i];

            power1 = val_a;
            power2 = max(a[i-pos_b], b[i-pos_a]);
        }

        r[i] = pow_(2, power1) + pow_(2, power2);
    }

    for (long long r_i : r) {
        cout << r_i%mod << ' ';
    }
    cout << '\n';
}
