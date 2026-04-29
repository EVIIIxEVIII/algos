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
    vector<vector<int>> pos(n+1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    // might be DP
    vector<bool> saw(n, false);
    vector<int> dp(n);
    dp[0] = 0;

    // dp[i] = max(dp[i], dp[j-1] + (i - j + 1));
    // dp[j-1] + (i - j + 1) = i + (dp[j-1] - j + 1);

    vector<int> best(n+1, -1);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];

        if (best[a[i]] != -1) {
            dp[i] = max(dp[i], i + best[a[i]]);
        }

        best[a[i]] = max(best[a[i]], dp[i-1] - i + 1);
    }

    cout << dp[n-1] << '\n';
}
