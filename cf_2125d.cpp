#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long q, long long e, long long p) {
    long long r = 1 % p;
    q %= p;
    while (e) {
        if (e & 1) r = r * q % p;
        q = q * q % p;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    constexpr long long prime = 998244353;
    vector<array<int, 4>> s(1);

    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        s.push_back({l, r, p, q});
    }

    // idea: to get the probability of some segment i, we need to know
    // the sum of the probabilities that all the cells before it are covered
    // and then multiply that value to the probability of the segment.
    //
    // the probability that some segment [l, r] will be used is equal to the
    // sum of probabilities that there is a segment that ends at l-1 times
    // the probability of the segment
    //
    // so the value at dp[r] will be equal to dp[l-1] * probability of the segment
    // [l, r]?
    //
    // also I will need this: a^(p-2) = a^(-1) mod p

    sort(s.begin(), s.end(), [](auto& x, auto& y) {
        return x[0] < y[0];
    });

    vector<int> dp(m+1, 0);
    dp[0] = 1;

    for (int i = 0; i <= m; ++i) {
        const auto& [l, r, p, q] = s[i];
        //dp[l] += mod_pow(q, prime - 2, prime) * p % prime;
        dp[r] += (dp[l-1] * (mod_pow(q, prime - 2, prime) * p % prime) % prime) % prime;
    }

    cout << dp[m] << '\n';

    return 0;
}
