#include <bits/stdc++.h>
using namespace std;

constexpr long long prime = 1e6 + 3;

long long pow_(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % prime;
        }

        a = (a * a) % prime;
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> fac(prime);
    fac[0] = 1;

    for (long long i = 1; i < prime; ++i) {
        fac[i] = (fac[i-1] * i) % prime;
    }

    vector<long long> inv(prime);
    inv[prime-1] = pow_(fac[prime-1], prime - 2);

    for (long long i = prime - 2; i >= 0; --i) {
        inv[i] = (inv[i + 1] * (i + 1)) % prime;
    }

    // important: p! mod p is 0, so if x >= p, then we have x! = 0 mod p;

    long long t; cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> b(n);

        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (long long i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // idea: if for all i, 1 <= i <= n, we have a_i * 2 > b_i, then the answer is sum(a_i - b_i)! % prime
        //
        // idea: if we find a p such that a_i * 2^p < b_i for all i, we can compute y = b_i - a_i * 2^p per each a_i and then
        // we could decompose that number in a binary form, such that we could add it at different stages of our p to
        // minimized the number of operations left. Let's denote the result of this operation as c_i, and then we could add
        // (b_i - c_i)! for all i.
        //

        long long p_max = INT_MAX;
        for (long long i = 0; i < n; ++i) {
            long long div = b[i] / a[i];
            if (div == 0) {
                p_max = 0;
                break;
            }

            p_max = min(p_max, 63LL - __builtin_clzll(div));
        }

        long long x = 0;
        long long ways = 1;

        if (p_max == 0) {
            for (long long i = 0; i < n; ++i) {
                x += b[i] - a[i];
            }

            if (x >= prime) {
                cout << x << ' ' << 0 << '\n';
                continue;
            }

            ways = fac[x];
            for (long long i = 0; i < n; ++i) {
                ways = (ways * inv[b[i] - a[i]]) % prime;
            }

            cout << x << ' ' << ways << '\n';
            continue;
        }

        // idea: after each doubling the number we added before that will be multiplied by 2^k where k is the number of remaining
        // doublings. Assume p_max = 3, thus we have 4 values:
        // x0 -> the value we add before any doubling
        // x1 -> the value we add after the first one
        // x2 -> the value we add after the second one
        // x3 -> the value we add after the third doubling (these values will be treated as b[i] - c[i])
        //
        // at the end we get: a_i * 2^3 + x0 * 2^3 + x1 * 2^2 + x2 * 2^1 * x3 * 2^0
        // so we need to decompose b[i] - a[i] * 2^3 long longo x0 * 2^3 + x1 * 2^2 + x2 * 2^1 + x3 * 2^0
        //
        // notice that with x0 we can use y >> p, because during p doublings our number will be shifted left p times.
        // thus using this information we are guaranteed that x3 is always 0, so we don't have to worry about it.
        // Also all next x1..xp are equal to 1 or 0.

        vector<long long> bucket(p_max+1, 0);
        vector<vector<long long>> per_i_bucket(n, vector<long long>(p_max+1));

        for (long long i = 0; i < n; ++i) {
            long long b_val = b[i];

            for (int j = 0; j < p_max; ++j) {
                if (b_val & 1) {
                    bucket[j+1]++;
                    per_i_bucket[i][j+1]++;
                }
                b_val >>= 1;
            }

            bucket[0] += (b[i] >> p_max) - a[i];
            per_i_bucket[i][0] += (b[i] >> p_max) - a[i];
        }

        for (int i = 0; i <= p_max; ++i) {
            x += bucket[i];
        }
        x += p_max;

        for (long long i = 0; i <= p_max; ++i) {
            if (bucket[i] >= prime) {
                ways = 0;
                break;
            }

            ways = (ways * fac[bucket[i]]) % prime;
            for (long long j = 0; j < n; ++j) {
                ways = (ways * inv[per_i_bucket[j][i]]) % prime;
            }
        }

        cout << x << ' ' << ways << '\n';
    }
    return 0;
}
