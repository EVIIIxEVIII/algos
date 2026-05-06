#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
}


constexpr long long mod = 1e9 + 7;

long long pow_(long long a, long long b) {
    a %= mod;
    long long ans = 1;

    while (b > 0) {
        if (b&1) {
            ans = (__int128)ans * a % mod;
        }

        a = (__int128)a * a % mod;
        b>>=1;
    }

    return ans;
}

void comb_mod() {
    long long n;
    cin >> n;

    vector<long long> fac(n+1);
    fac[0] = 1;

    for (long long i = 1; i <= n; ++i) {
        fac[i] = (__int128)fac[i-1] * i % mod;
    }

    // n!/((n - k)! * k!)

    vector<long long> inv(n+1);
    inv[n] = pow_(fac[n], mod - 2);

    for (long long i = n - 1; i > 0; --i) {
        inv[i] = (__int128)inv[i+1] * (i+1) % mod;
    }
}

