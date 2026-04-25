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

    array<vector<char>, 2> g;
    g.fill(vector<char>(n));

    for (int i = 0; i < n; ++i) {
        cin >> g[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> g[1][i];
    }

    constexpr int INF = 1e9 + 3;
    vector<int> dp(n+1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int j = i - 1;
        dp[i] = dp[i - 1] + (g[0][j] != g[1][j]);

        if (i > 1) {
            dp[i] = min(dp[i], dp[i-2] + (g[0][j-1] != g[0][j]) + (g[1][j-1] != g[1][j]));
        }
    }

    cout << dp[n] << '\n';
}
