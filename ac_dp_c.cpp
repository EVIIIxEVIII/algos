#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(3, vector<int>(n));
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];

    for (int i = 1; i < n; ++i) {
        dp[0][i] = max(a[i] + dp[1][i-1], a[i] + dp[2][i-1]);
        dp[1][i] = max(b[i] + dp[0][i-1], b[i] + dp[2][i-1]);
        dp[2][i] = max(c[i] + dp[0][i-1], c[i] + dp[1][i-1]);
    }

    cout << max({dp[0][n-1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
}
