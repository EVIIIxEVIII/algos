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
    int n;
    cin >> n;

    vector<vector<int>> h(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Let's say we have something like this:
    //
    // 22222
    //    111111
    //
    // then we can fix it by either applying the operations to the odd columns only or the even columns only.
    //
    // If we have something like this:
    //
    // 22222
    //        11111
    //
    // then the two blocks can be processed separately, in other words, we can apply the cheapeast
    // parity to the first block and the cheapest parity to the second one.
    //
    // So fixes must be applied every 2nd row/column and the fix must not break any existing cells. I.e
    // when apply the fix to column i, there must not be a value g[i][j] such that g[i][j] + 1 == g[i][j-1] or g[i][j+1]
    //
    // if we have the choise between parities we pick the cheapest one.
    //
    // so when doing column operations we can't introduce any row fixable pairs, because we uniformly increase the whole column,
    // what we can introduce however, as mentioned positions like g[i][j] such that g[i][j] + 1 == g[i][j-1] or g[i][j+1], which
    // can be fixed only and only by doing other column operations. So assume a situation like this:
    // 2 1
    // 2 2
    // 1 2
    // no matter how we try to fix that [2, 2] second row, we just aren't able to do so, because of the inverse [2, 1] and [1, 2]
    //
    // Thus column operations and row operations are basically independent of each other and can be checked separately.
    //
    // dp[0][i] stores the best cost up to column i if we don't fix column i
    // dp[1][i] stores the best cost up to column i if we did fix it

    const long long INF = LLONG_MAX / 4;
    array<vector<long long>, 2> dp_col{ vector<long long>(n, INF), vector<long long>(n, INF) };

    dp_col[0][0] = 0LL;
    dp_col[1][0] = b[0];

    auto check_col = [&](int j, int cur, int prev) {
        for (int i = 0; i < n; ++i) {
            if (h[i][j] + cur == h[i][j-1] + prev) {
                return false;
            }
        }

        return true;
    };

    for (int j = 1; j < n; ++j) {
        if (check_col(j, 0, 0)) {
            dp_col[0][j] = min(dp_col[0][j-1], dp_col[0][j]);
        }

        if (check_col(j, 1, 0)) {
            dp_col[1][j] = min(dp_col[0][j-1] + b[j], dp_col[1][j]);
        }

        if (check_col(j, 0, 1)) {
            dp_col[0][j] = min(dp_col[1][j-1], dp_col[0][j]);
        }

        if (check_col(j, 1, 1)) {
            dp_col[1][j] = min(dp_col[1][j-1] + b[j], dp_col[1][j]);
        }
    }

    if (dp_col[0][n-1] == INF && dp_col[1][n-1] == INF) {
        cout << -1 << '\n';
        return;
    }

    auto check_row = [&](int i, int cur, int prev) {
        for (int j = 0; j < n; ++j) {
            if (h[i][j] + cur == h[i-1][j] + prev) {
                return false;
            }
        }

        return true;
    };

    array<vector<long long>, 2> dp_row{ vector<long long>(n, INF), vector<long long>(n, INF) };
    dp_row[0][0] = 0LL;
    dp_row[1][0] = a[0];

    for (int i = 1; i < n; ++i) {
        if (check_row(i, 0, 0)) {
            dp_row[0][i] = min(dp_row[0][i-1], dp_row[0][i]);
        }

        if (check_row(i, 1, 0)) {
            dp_row[1][i] = min(dp_row[0][i-1] + a[i], dp_row[1][i]);
        }

        if (check_row(i, 0, 1)) {
            dp_row[0][i] = min(dp_row[1][i-1], dp_row[0][i]);
        }

        if (check_row(i, 1, 1)) {
            dp_row[1][i] = min(dp_row[1][i-1] + a[i], dp_row[1][i]);
        }
    }

    if (dp_row[0][n-1] == INF && dp_row[1][n-1] == INF) {
        cout << -1 << '\n';
        return;
    }

    cout << min(dp_row[0][n-1], dp_row[1][n-1]) + min(dp_col[0][n-1], dp_col[1][n-1]) << '\n';
}
