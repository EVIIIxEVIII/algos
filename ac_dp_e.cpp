#include <bits/stdc++.h>
#include <climits>
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
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    vector<vector<long long>> dp(n, vector<long long>(1e3 * 100 + 1, LLONG_MAX / 4));
    dp[0][0] = 0;
    dp[0][a[0].second] = a[0].first;

    for (int i = 1; i < n; ++i) {
        auto [wi, vi] = a[i];

        for (int v = 0; v <= 1e3 * 100; ++v) {
            dp[i][v] = dp[i-1][v];

            if (v >= vi) {
                dp[i][v] = min(dp[i-1][v], dp[i-1][v - vi] + wi);
            }
        }
    }

    for (int i = 1e3 * 100; i >= 0; --i) {
        if (dp[n-1][i] <= k) {
            cout << i << '\n';
            return;
        }
    }
}
