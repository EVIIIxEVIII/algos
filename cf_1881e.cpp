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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp from right to left or something?

    vector<int> dp(n + 1);
    dp[n-1] = 1;

    for (int i = n - 2; i >= 0; --i) {
        int use;

        if (i + a[i] < n) {
            use = dp[i + a[i] + 1];
        } else {
            use = n - i;
        }

        dp[i] = min(dp[i+1] + 1, use);
    }

    cout << dp[0] << '\n';
}
