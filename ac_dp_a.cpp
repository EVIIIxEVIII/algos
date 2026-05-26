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
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const long long INF = LLONG_MAX / 4;
    vector<long long> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));

        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
        }
    }

    cout << dp[n - 1] << '\n';
}
