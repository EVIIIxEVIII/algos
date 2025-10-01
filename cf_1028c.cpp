#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int bottom = a[0];
        int ops = 0;

        for (int i = 1; i < n; ++i) {
            bottom = gcd(bottom, a[i]);
        }

        int maxNum = -1;
        for (int i = 0; i < n; ++i) {
            a[i] /= bottom;
            maxNum = max(maxNum, a[i]);
        }

        vector<int> dp(maxNum+1, INT_MAX);
        for (int i = 0; i < n; ++i) dp[a[i]] = 0;

        for (int i = maxNum; i >= 1; --i) {
            if (dp[i] >= INT_MAX) continue;
            for (int j = 0; j < n; ++j) {
                int x = gcd(a[j], i);
                dp[x] = min(dp[x], dp[i] + 1);
            }
        }

        int minPath = dp[1];
        int ans = minPath;

        for (int i = 0; i < n; ++i) {
            if (a[i] != 1) ans++;
        }

        // if minPath > 0 it means we have already changed one element to 1
        // by using minPath steps, so decrease by 1 to avoid double counting
        // editorial makes it very confusing
        cout << ans - (minPath > 0) << '\n';

        // gcd(6, 14) = 2
        // gcd(6, 15) = 3
        // gcd(14, 15) = 1
        // [6, 14, 1]
        // [6, 1,  1]
        // [1, 1, 1]
    }
    return 0;
}
