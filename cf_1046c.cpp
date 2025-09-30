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

        vector<long long> dp(n+1, 0);
        vector<vector<int>> pos(n+1);

        for (int i = 0; i < n; ++i) {
            pos[a[i]].push_back(i);

            long long prevDp = i - 1 >= 0 ? dp[i - 1] : 0;
            if (pos[a[i]].size() >= a[i]) {
                long long beforeBlock = pos[a[i]][pos[a[i]].size() - a[i]] - 1;
                beforeBlock = beforeBlock >= 0 ? dp[beforeBlock] : 0;

                dp[i] = max(prevDp, beforeBlock + a[i]);
            } else {
                dp[i] = prevDp;
            }
       }

       cout << dp[n-1] << '\n';
    }
    return 0;
}
