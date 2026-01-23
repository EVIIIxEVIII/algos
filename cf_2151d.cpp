#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;


        vector<long long> fac(n+1);
        vector<long long> inv_fac(n+1);

        fac[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i-1] * i % mod;
        }

        inv_fac[n] = modpow(fac[n], mod - 2);
        for (int i = n; i >= 1; --i) {
            inv_fac[i-1] = inv_fac[i] * i % mod;
        }

        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        long long ans = 1;
        int used = 0;
        for (int i = n; i >= 1; --i) {
            long long forced = a[i];
            long long total = max(0, n + 2 - i * 2);
            long long have = total - used;

            if (forced > have) {
                ans = 0;
                break;
            }

            ans = ans * fac[have] % mod * inv_fac[have - forced] % mod * inv_fac[forced] % mod;
            used += forced;
        }

        if (used != n) ans = 0;
        cout << ans << '\n';
    }

    return 0;
}
