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
    long long n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // the idea is to probably compute the reverse: the number
    // of segments where we have 0 at the end and then subtract that
    // value from the total number of possible segments.
    // prefix + suffix sum?
    //
    // O(n^2) solution: for each l compute a prefix sum from l to n - 1, then
    // count the number of number in the prefix sum such that p[i] %

    vector<int> dp(n+1, 0);
    int r = 0;
    long long sum = 0;
    long long ans = 0;

    for (int l = 0; l < n && r < n;) {
        while (r < n && sum <= x) {
            sum += a[r];
            r++;
        }

        while (l < n && r <= n && sum > x) {
            dp[r] += dp[l] + 1;
            ans += dp[l] + 1;
            sum -= a[l];
            l++;
        }
    }

    long long output = n * (n + 1LL) / 2LL - ans;
    // dp[r] = dp[r-1] + dp[l-1]
    cout << output << '\n';
}
