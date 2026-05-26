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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n, LLONG_MAX / 4);

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < min(i + k + 1, n); ++j) {
            dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
        }
    }

    cout << dp[n - 1] << '\n';
}
