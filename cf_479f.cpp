#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxVal = 0;
    for (int i = 0; i < n; ++i) {
        maxVal = max(a[i], maxVal);
    }

    unordered_map<int, int> dp;
    dp.reserve(n * 2);
    dp.max_load_factor(0.7);
    for (int i = 0; i < n; ++i) {
        if (!dp.count(a[i])) {
            dp[a[i]] = 1;
        }

        if (dp.count(a[i] - 1)) {
            dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        }
    }

    int ans = 1;
    int end = a[0];

    for (int i = 0; i < n; ++i) {
        if (dp[a[i]] > ans) {
            end = a[i];
            ans = dp[a[i]];
        }
    }

    cout << ans << '\n';
    int val = end - ans + 1;

    for (int i = 0; i < n; ++i) {
        if (a[i] == val) {
            cout << i+1 << ' ';
            val++;
        }
    }

    cout << '\n';

    return 0;
}
