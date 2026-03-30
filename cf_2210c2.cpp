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

    int ans = 0;
    vector<bool> changed(n, false);
    for (int i = 0; i < n; ++i) {
        int left = i > 0 ? gcd(a[i], a[i-1]) : 1;
        int right = i < n - 1 ? gcd(a[i], a[i+1]) : 1;

        if (lcm(left, right) != a[i]) {
            changed[i] = true;
            ans++;
        }
    }

    auto sieve = [&](long long n) -> vector<long long> {
        vector<bool> is_prime(n+1, true);
        if (n>=1) is_prime[1] = false;
        if (n>=0) is_prime[0] = false;

        for (long long i = 2; i * i * 1LL <= n; ++i) {
            if (is_prime[i]) {
                for (long long j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        vector<long long> primes;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    };

    vector<long long> base_primes = sieve(31623); // sqrt(1e9) = 31623

    // (L, R]
    auto prime_count = [&](int L, int R) -> pair<int,int> {
        if (L >= R) return { 0, 0 };
        long long lo = 1LL * L + 1;
        long long hi = R;

        vector<bool> is_prime(hi - lo + 1, true);

        for (long long p : base_primes) {
            long long pp = 1LL * p * p;
            if (pp > hi) break;

            long long start = max(pp, ((lo + p - 1) / p) * 1LL * p);
            for (long long x = start; x <= hi; x += p) {
                is_prime[x - lo] = false;
            }
        }

        if (lo == 1) {
            is_prime[0] = false;
        }

        long long count = 0;
        long long first = 0;

        for (int i = 0; i < (int)is_prime.size(); ++i) {
            if (is_prime[i]) {
                count++;
                if (first == 0) {
                    first = lo + i;
                }
            }
        }

        return {count, first};
    };

    //for (int i = 0; i < n;) {
    //    if (changed[i]) {
    //        i++; continue;
    //    }

    //    int prev_c = 0;
    //    int prev_p = 0;

    //    while (i < n && !changed[i]) {
    //        auto [c, p] = prime_count(a[i], b[i]);
    //        if (prev_c >= 2 || c >= 2 || (c == 1 && prev_c == 1 && prev_p != p)) {
    //            cout << c << ' ' << p << '\n';
    //            ans++;
    //        }
    //        prev_c = c; prev_p = p;
    //        i++;
    //    }
    //}

    cout << ans << '\n';
}
