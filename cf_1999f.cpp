#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

long long mod_pow(long long a, long long b) {
    a %= mod;
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans % mod;
}


void solve() {
    long long n, k;
    cin >> n >> k;

    vector<int> a(n);
    long long b = 0, w = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            b++;
        } else {
            w++;
        }
    }

    vector<long long> fac(n+1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fac[i] = (fac[i-1] * i) % mod;
    }

    vector<long long> inv(n+1);
    inv[n] = mod_pow(fac[n], mod - 2);
    for (long long i = n - 1; i >= 0; --i) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }

    // n choose k, but how to compute the number of sequences with #1 > #0?
    // n choose k/2 + 1?
    // we can think of 1s as black balls and 0s as white balls, now what we need to do is
    // to compute the number of ways to pick k balls out of n balls such that the number of black
    // balls is greater than the number of white balls.

    // so something like b chose j times w choose k - j where w is the number of 0s and b the number of 1s and we loop through j
    // from k/2 + 1 till min(b, k);

    long long ans = 0;
    for (int j = k/2 + 1; j <= min(b, k); ++j) {
        if (w - k + j < 0 || b - j < 0) continue;
        long long black_balls = ((fac[b] * inv[j]) % mod) * inv[b - j] % mod;
        long long white_balls = ((fac[w] * inv[k - j]) % mod) * inv[w - k + j] % mod;

        ans = (ans + (black_balls * white_balls) % mod) % mod;
    }

    cout << ans << '\n';
}
