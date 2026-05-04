#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    long long ans = 1;
    a %= mod;

    while(b > 0) {
        if (b & 1) {
            ans = ans * a % mod;
        }

        a = (__int128)a * a % mod;
        b >>= 1;
    }

    return ans % mod;
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    // 1. for k = 1 and k = 0 and more generally k = 10^x all numbers n 10^l <= n < 10^r satisfy k * d(n) = d(n * k)
    // so the count will be 10^r - 10^l.
    // 2. for k >= 2 and k <= 9 we have all the numbers formed from 0 till floor(10 / k) so each positions has 1 + floor(10 / k) options
    // 3. for k != 10^x and k > 10 only numbers n = 10^x satisfy the constraint?

    if (k == 1 || k == 0) {
        cout << (pow_(10, r) - pow_(10, l) + mod) % mod << '\n';
    } else if (k % 10 == 0) {
        cout << 0 << '\n';
    } else if (k >= 2 && k <= 9) {
        // (r - 1) - (l - 1) = r - 1 - l + 1 = r - l
        // 2^(l-1) + 2^(l) + 2^(l + 1) + ... + 2^(r - 1)
        // 2^(l-1) * (2^0 + 2^1 + 2^2 + 2^3 + ...) = 2^(l-1) * 2^(r - l)
        // basically ignore the top set 1 and the rest l - 1 zeros can be either 0 or 1.

        long long base = 1 + 9 / k;
        long long ans = (pow_(base, r) - pow_(base, l) + mod) % mod;
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}
