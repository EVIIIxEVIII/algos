#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    long long mod_pow(long long a, long long b) {
        a %= mod;

        long long ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = ans * a % mod;
            }

            a = a * a % mod;
            b >>= 1;
        }
        return ans % mod;
    }

    int nchoosek(long long n, long long k) {
        k = min(n, n - k);

        long long top = 1;
        long long bottom = 1;

        for (long long i = 1; i <= k; ++i) {
            top = top * (n - k + i) % mod;
            bottom = bottom * i % mod;
        }

        return top * mod_pow(bottom, mod - 2) % mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        return (nchoosek(n-1, k) * 2) % mod;
    }
};
