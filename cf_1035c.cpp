#include <bits/stdc++.h>

using namespace std;

static inline unsigned long long next_pow2_strict(unsigned long long x) {
    unsigned long long p = 1ULL << (64 - __builtin_clzll(x));
    if (p == x) p <<= 1;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        long long n, l, r, k;
        cin >> n;
        cin >> l;
        cin >> r;
        cin >> k;

        if (n % 2) {
            cout << l << '\n';
        } else if (n >= 4) {
            long long second = next_pow2_strict(l);

            if (second <= r) {
                cout << (k > n-2 ? second : l) << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
   }

    return 0;
}
