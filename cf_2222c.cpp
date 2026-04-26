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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> s = a;
    sort(s.begin(), s.end());

    int T = s[n/2];

    vector<long long> pref_ge(n+1);
    vector<long long> pref_le(n+1);

    pref_ge[0] = 0;
    pref_le[0] = 0;

    for (int i = 1; i <= n; ++i) {
        pref_ge[i] = pref_ge[i-1] + (a[i - 1] >= T ? 1 : -1);
        pref_le[i] = pref_le[i-1] + (a[i - 1] <= T ? 1 : -1);
    }

    constexpr long long NEG_INF = - 1e18;
    vector<long long> dp(n+1, NEG_INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((i - j) % 2 == 0) {
                continue;
            }

            long long ge_cnt = pref_ge[i] - pref_ge[j]; // in region [j, i-1]
            long long le_cnt = pref_le[i] - pref_le[j];

            if (dp[j] != NEG_INF && ge_cnt > 0 && le_cnt > 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n] << '\n';
}
