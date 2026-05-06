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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    // dp? min sliding window?

    vector<vector<long long>> dp(n, vector<long long>(m, 1));
    for (int i = 0; i < n; ++i) {
        deque<long long> deq; // ascending order
        deq.push_back(0);

        for (int j = 1; j < m; ++j) {
            if (!deq.empty() && j - deq.front() > d + 1) {
                deq.pop_front();
            }

            long long best = deq.front();
            dp[i][j] = dp[i][best] + g[i][j] + 1;

            while (!deq.empty() && dp[i][deq.back()] > dp[i][j]) {
                deq.pop_back();
            }

            deq.push_back(j);
        }
    }

    long long ans = LLONG_MAX;
    long long current = 0;
    for (int i = 0; i < k; ++i) {
        current += dp[i][m-1];
    }
    ans = current;

    for (int i = k; i < n; ++i) {
        current -= dp[i - k][m - 1];
        current += dp[i][m - 1];
        ans = min(ans, current);
    }
    cout << ans << '\n';
}
