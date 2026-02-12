#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        vector<long long> b(n);

        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // idea: this is probably one of those binary search with upper bound (TTTTFFFF style)
        // idea: it's not because if price > b[i] no outcomes follow, i.e no reviews are left
        //
        // main idea: when having thresholds like when you are given n segments [a_i, b_i],
        // something happens from [0, a_i], something happens from (a_i, b_i] and something
        // happens from (b_i, inf) then you only need to check the bounds, because the changes
        // happens only at them.
        // more general idea: when thinking about a problem think when the state changes with respect to
        // some bounds.

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ans = 0;

        for (long long i = 0; i < n; ++i) {
            auto it_b = lower_bound(b.begin(), b.end(), a[i]);
            long long seen_b = it_b - b.begin();
            long long less_a = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
            long long r = less_a - seen_b;

            if (r <= k) {
                ans = max(ans, a[i] * (n - seen_b) * 1LL);
            }
        }

        for (long long i = 0; i < n; ++i) {
            long long seen_b = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
            auto it_a = lower_bound(a.begin(), a.end(), b[i]);
            long long r = (it_a - a.begin()) - seen_b;

            if (r <= k) {
                ans = max(ans, b[i] * (n - seen_b) * 1LL);
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
