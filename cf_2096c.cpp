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

    vector<pair<int,int>> seg_col;
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && h[i][l] == h[i][r]) {
                r++;
            }

            if (r - l >= 2) {
                seg_col.push_back({l, r});
            }

            l = r;
        }
    }

    sort(seg_col.begin(), seg_col.end());

    vector<pair<int,int>> mer_seg_col;
    for (int i = 0; i < (int)seg_col.size();) {
        int l = seg_col[i].first;
        int r = seg_col[i].second;
        int j = i + 1;

        while (j < (int)seg_col.size() && seg_col[j].first < r) {
            r = max(r, seg_col[j].second);
            j++;
        }

        mer_seg_col.push_back({ l, r });
        i = j;
    }

    auto check_col_seg = [&](bool even, int l, int r) -> long long {
        if (even) l++;
        long long cost = 0;

        for (int j = l; j < r; j += 2) {
            for (int i = 0; i < n; ++i) {
                if (j - 1 >= 0 && h[i][j] + 1 == h[i][j-1]) {
                    return LLONG_MAX;
                }

                if (j + 1 < n && h[i][j] + 1 == h[i][j + 1]) {
                    return LLONG_MAX;
                }
            }

            cost += b[j];
        }

        return cost;
    };

    long long ans = 0;
    for (auto& [l, r] : mer_seg_col) {
        long long even = check_col_seg(true, l, r);
        long long odd = check_col_seg(false, l, r);

        if (even == LLONG_MAX && odd == LLONG_MAX) {
            cout << -1 << '\n';
            return;
        }

        ans += min(even, odd);
    }

    vector<pair<int,int>> seg_row;
    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && h[l][j] == h[r][j]) {
                r++;
            }

            if (r - l >= 2) {
                seg_row.push_back({l, r});
            }

            l = r;
        }
    }

    sort(seg_row.begin(), seg_row.end());

    vector<pair<int,int>> mer_seg_row;
    for (int i = 0; i < (int)seg_row.size();) {
        int l = seg_row[i].first;
        int r = seg_row[i].second;
        int j = i + 1;

        while (j < (int)seg_row.size() && seg_row[j].first < r) {
            r = max(r, seg_row[j].second);
            j++;
        }

        mer_seg_row.push_back({ l, r });
        i = j;
    }

    auto check_row_seg = [&](bool even, int l, int r) -> long long {
        if (even) l++;
        long long cost = 0;

        for (int i = l; i < r; i += 2) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0 && h[i][j] + 1 == h[i - 1][j]) {
                    return LLONG_MAX;
                }

                if (i + 1 < n && h[i][j] + 1 == h[i + 1][j]) {
                    return LLONG_MAX;
                }
            }

            cost += a[i];
        }

        return cost;
    };

    for (auto& [l, r] : mer_seg_row) {
        long long even = check_row_seg(true, l, r);
        long long odd = check_row_seg(false, l, r);

        if (even == LLONG_MAX && odd == LLONG_MAX) {
            cout << -1 << '\n';
            return;
        }

        ans += min(even, odd);
    }

    cout << ans << '\n';
}
