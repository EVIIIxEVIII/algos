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

    sort(a.begin(), a.end());

    int maxVal = 0;

    for (int i = 0; i < n; ++i) {
        maxVal = max(maxVal, a[i]);
    }

    vector<long long> dp(maxVal+1, 0);
    for (int i = 0; i < n; ++i) {
        dp[a[i]] += a[i];
    }

    for (int i = 2; i <= maxVal; ++i) {
        dp[i] = max(dp[i-1], dp[i] + dp[i-2]);
    }

    cout << dp[maxVal] << '\n';

    return 0;
}
