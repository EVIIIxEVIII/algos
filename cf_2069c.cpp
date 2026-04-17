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

constexpr long long mod = 998244353;
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n);
    vector<long long> prefix_dp(n);
    vector<long long> prefix_cnt_1(n);
    prefix_cnt_1[0] = 0;
    prefix_dp[0] = 0;

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        prefix_cnt_1[i] = prefix_cnt_1[i-1] + (a[i-1] == 1);
        prefix_dp[i] = prefix_dp[i-1] + dp[i-1];

        if (a[i] == 2) {
            dp[i] = (prefix_cnt_1[i] + prefix_dp[i]) % mod;
        } else if (a[i] == 3) {
            ans = (ans + prefix_dp[i]) % mod;
        }
    }

    cout << ans % mod << '\n';
}
