#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // idea: for all i, there must be at least two same consecutive elements
        // a[i] == a[i+1] or a[i-1] == a[i] for all i.
        //
        // idea: for every block [i, j] the minimum cost would be a values c
        // such that sum from i to j of abs(a[i], c) would be minimized.
        // It would probably be possible to dp on the start and the end of
        // each block?
        //
        // idea: mb a prefix sum where prefix[j] - prefix[i] would be the cost to
        // make the block [i, j] equal?

        auto cost2 = [](int a, int b) {
            return abs(a - b) * 1LL;
        };

        auto cost3 = [](int a, int b, int c) {
            if (a > b) { swap(a, b); }
            if (b > c) { swap(b, c); }
            if (a > b) { swap(a, b); }
            return abs(c - a) * 1LL;
        };

        long long ans = LLONG_MAX;
        for (int shift = 0; shift < 4; ++shift) {
            vector<long long> dp(n);

            dp[0] = LLONG_MAX;
            dp[1] = cost2(a[0], a[1]);
            dp[2] = cost3(a[0], a[1], a[2]);

            for (int i = 3; i < n; ++i) {
                // minimum between treating a[i] as the end of a
                // block of size 2 or block of size 3.

                if (dp[i - 2] != LLONG_MAX) {
                    dp[i] = dp[i - 2] + cost2(a[i], a[i - 1]);
                }

                if (dp[i - 3] != LLONG_MAX) {
                    dp[i] = min(dp[i], dp[i - 3] + cost3(a[i], a[i - 1], a[i - 2]));
                }
            }

            for (int i = 1; i < n; ++i) {
                swap(a[i], a[i-1]);
            }

            ans = min(ans, dp[n-1]);
        }

        cout << ans << '\n';
    }
    return 0;
}
