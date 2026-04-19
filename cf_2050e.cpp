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
    string a;
    string b;
    string c;

    cin >> a >> b >> c;

    // for character a[i] to be used all the characters before it in a[i] must have been used
    // before it AND some number of characters from b[i] must have been used.

    // the order of characters must be preserved, i.e if a character a[i] appears after a[j] they must appear
    // in this same order in c.

    // when we have a sequence c formed from sequence a and sequence b where the order is preserved try 2D dp.

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
    }

    for (int i = 1; i <= m; ++i) {
        dp[0][i] = dp[0][i-1] + (b[i-1] != c[i-1]);
    }

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            dp[x][y] = min(
                dp[x-1][y] + (a[x-1] != c[x+y-1]),
                dp[x][y-1] + (b[y-1] != c[x+y-1])
            );
        }
    }

    cout << dp[n][m] << '\n';
}
