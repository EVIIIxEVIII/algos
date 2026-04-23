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
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<long long> prefix(n+1);
    prefix[0] = 0;

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + a[i-1];
    }

    auto value = [&] (long long u, long long s) -> long long {
        return u * s - (s - 1) * s / 2;
    };

    for (int i = 0; i < q; ++i) {
        long long l, u;
        cin >> l >> u;

        // u * s - (s - 1) * s / 2
        // u * s - (s*s - s) / 2
        // s = 1/2 + u

        int lo = l;
        int hi = n;

        // TTFF
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            if (prefix[m] - prefix[l - 1] >= u) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }

        int ans = l;
        long long best = value(u, prefix[l] - prefix[l-1]);

        for (int idx : {lo - 1, lo}) {
            if (idx < l || idx > n) continue;

            long long s = prefix[idx] - prefix[l-1];
            long long cur = value(u, s);

            if (cur > best) {
                best = cur;
                ans = idx;
            }
        }

        cout << ans << ' ';
    }
    cout << '\n';
}
