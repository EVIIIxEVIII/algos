#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<array<long long, 4>> dp(n + 1);

    dp[0][0] = 0;
    dp[0][1] = INT_MAX;
    dp[0][2] = INT_MAX;
    dp[0][3] = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'h') {
            dp[i][0] = dp[i - 1][0] + a[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3];
        } else if (s[i-1] == 'a') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + a[i];
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = dp[i-1][3];
        } else if (s[i-1] == 'r') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2] + a[i];
            dp[i][3] = min(dp[i-1][2], dp[i-1][3]);
        } else if (s[i-1] == 'd') {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3] + a[i];
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';

    return 0;
}
