#include <bits/stdc++.h>
#include <climits>
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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> c = a;
    sort(c.begin(), c.end());
    int target = c[n/2];

    vector<long long> pref_ge(n + 1, 0);
    vector<long long> pref_le(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref_ge[i+1] = pref_ge[i] + (a[i] >= target ? 1 : -1);
        pref_le[i+1] = pref_le[i] + (a[i] <= target ? 1 : -1);
    }

    constexpr long long NEG_INF = -1e18;
    vector<long long> dp(n + 1, NEG_INF);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; ++j) {
            if ((i - j) % 2 == 0) {
                continue;
            }

            long long sum_ge = pref_ge[i] - pref_ge[j];
            long long sum_le = pref_le[i] - pref_le[j];

            if (sum_ge > 0 && sum_le > 0 && dp[j] != NEG_INF) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n] << '\n';
}
