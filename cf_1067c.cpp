#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int k;
        cin >> k;

        vector<long long> a(n);
        vector<long long> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // idea: the first move of A must be the best move positive move, and the move of B
        // must be the best negative move, i.e the reverse of A move
        // so the solution would be: compute the best S(i, j) on the original array
        // then compute S(i, j) with the posibility to do one operation which will increase the sum
        // check k % 2 and select the appropriate one

        long long ans = a[0];
        if (k % 2 == 0) {
            long long intermediate = a[0];

            for (int i = 1; i < n; ++i) {
                intermediate = max(intermediate + a[i], a[i]);
                ans = max(intermediate, ans);
            }

            std::cout << ans << '\n';
        } else {
            if (n == 1) {
                std::cout << a[0] + b[0] << '\n';
                continue;
            }

            vector<long long> dp(n);
            vector<long long> dpRev(n);

            dp[0] = a[0];
            dpRev[n-1] = a[n-1];

            long long cur = a[0];
            long long curRev = a[n-1];

            for (int i = 1; i < n; ++i) {
                dp[i] = max(dp[i - 1] + a[i], a[i]);
            }

            for (int i = n-2; i >= 0; --i) {
                dpRev[i] = max(a[i], dpRev[i + 1] + a[i]);
            }

            for (int i = 0; i < n; ++i) {
                ans = max(ans, dp[i] + dpRev[i] - a[i] + b[i]);
            }

            std::cout << ans << '\n';
        }


    }
    return 0;
}
