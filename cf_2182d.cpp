#include <bits/stdc++.h>
using namespace std;

constexpr long long prime = 998244353;
long long power(long long a, long long b) {
    long long res = 1;
    long long temp = a % prime;

    while (b > 0) {
        if (b & 1) {
            res = res * temp % prime;
        }

        temp = temp * temp % prime;
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> p(51);
    p[0] = 1;

    for (int i = 1; i <= 50; ++i) {
        p[i] = (i * p[i-1]) % prime;
    }

    vector<long long> inv(51);
    inv[50] = power(p[50], prime - 2);

    for (int i = 50; i > 0; --i) {
        inv[i - 1] = inv[i] * i % prime;
    }

    auto C = [&](long long n, long long k) {
        if (k < 0 || k > n) return 0LL;
        return p[n] * inv[k] % prime * inv[n - k] % prime;
    };

    auto P = [&](long long x) { return p[x]; };

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n+1);
        for (int i = 0; i <= n; ++i) {
            cin >> a[i];
        }

        long long k = accumulate(a.begin(), a.end(), 0LL) / n;

        long long ones = 0;
        long long zeros = 0;

        bool not_valid = false;

        for (int i = 1; i <= n; ++i) {
            long long x = min(a[i], k);
            a[i] -= x;
            a[0] -= k - x;

            if (a[i]) ones++;
            else zeros++;

            not_valid |= a[i] > 1 || a[0] < 0;
        }

        not_valid |= a[0] > zeros;

        if (not_valid) {
            cout << 0 << '\n';
            continue;
        }

        long long x = zeros - a[0];
        long long ans = P(x) % prime * P(n - x) % prime * C(zeros, x) % prime;

        cout << ans << '\n';
    }
    return 0;
}
