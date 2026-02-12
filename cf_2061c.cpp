#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        // idea: use a 2 state dp where:
        // - dp[0][i] number of configurations so far where i is a liar
        // - dp[1][i] number of configurations so far where i is not a liar
        //
        // idea: for each dp[1] go back and compare a[i] with all the a[j] such that j < i
        // if a[j] > a[i] then this mf must be a liar from a[i] perspective otherwise it can be either
        // a liar or not.
        //
        // idea: dp[i] - number of configurations before i where person i is honest. If i is honest then there are a[i]
        // liars to their left, if a[i-1] is honest then a[i] == a[i-1] so dp[i] += dp[i-1], if a[i] != a[i-1], then we check if
        // a[i-2] == a[i] - 1 if true we do dp[i] += dp[i-2], otherwise it is impossible since a[i] is forced to be a liar, since
        // 2 liars a[i-1] and a[i-2] cannot stand near each other.

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n == 1) {
            if (a[0] == 0) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
            continue;
        }

        vector<int> dp(n, 0);
        dp[0] = a[0] == 0;
        dp[1] = (a[1] == 0 && a[1] == a[0]) || (a[1] == 1);

        for (int i = 2; i < n; ++i) {
            if (a[i] == a[i-1]) {
                dp[i] = (dp[i] + dp[i-1]) % 998244353;
            }

            if (a[i] - 1 == a[i-2]) {
                dp[i] = (dp[i] + dp[i-2]) % 998244353;
            }
        }

        cout << (dp[n-1] + dp[n-2]) % 998244353 << '\n';
    }
    return 0;
}
