#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int q; cin >> q;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<long long> a(q);
    vector<long long> b(q);

    for (int i = 0; i < q; ++i) {
        cin >> a[i];
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i) {
        vector<long long> dp(n+1, -4e18);
        long long max1 = 0;
        long long max2 = 0;

        for (int j = 0; j < n; ++j) {
            if (max1 == dp[c[j]]) {
                dp[c[j]] = max(dp[c[j]], dp[c[j]] + v[j] * a[i]);
                dp[c[j]] = max(dp[c[j]], max2 + v[j] * b[i]);
                max1 = dp[c[j]];
            } else {
                dp[c[j]] = max(dp[c[j]], dp[c[j]] + v[j] * a[i]);
                dp[c[j]] = max(dp[c[j]], max1 + v[j] * b[i]);

                max2 = max(dp[c[j]], max2);

                if (max2 > max1) {
                    swap(max1, max2);
                }
            }
        }

        cout << max1 << '\n';
    }

    return 0;
}
