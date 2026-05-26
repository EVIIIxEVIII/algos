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
    int N, W;
    cin >> N >> W;

    vector<pair<int,int>> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    vector<vector<long long>> dp(N, vector<long long>(W + 1));
    dp[0][a[0].first] = a[0].second;

    for (int i = 1; i < N; ++i) {
        auto [wi, vi] = a[i];

        for (int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i-1][w];

            if (w >= wi) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wi] + vi);
            }
        }
    }

    long long ans = 0;
    for (int w = 0; w <= W; ++w) {
        ans = max(ans, dp[N - 1][w]);
    }

    cout << ans << '\n';
}
