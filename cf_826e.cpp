#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n+2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<bool> dp(n+2, false);
        dp[0] = true;
        dp[n+1] = true;

        for (int i = 1; i <= n; ++i) {
            if (i - a[i] >= 1) {
                dp[i] = dp[i] || dp[i - a[i] - 1];
            }

            if (i + a[i] <= n) {
                dp[i + a[i]] = dp[i+a[i]] || dp[i - 1];
            }
        }

        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}
