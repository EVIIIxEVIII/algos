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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    vector<pair<int,int>> x(n);
    vector<pair<int,int>> y(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;

        x[i] = { a[i].first, i };
        y[i] = { a[i].second, i };
    }

    // proly some greedy has to work.
    //
    // we somehow need to quantify the amount of overlapping that is going on on the x axis and
    // y axis, when the distances are projected onto them

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<int> xside(n);
    vector<int> yside(n);

    for (int i = 0; i < n; ++i) {
        auto [xp, xi] = x[i];
        auto [yp, yi] = y[i];

        xside[xi] = i < n/2 ? 0 : 1;
        yside[yi] = i < n/2 ? 0 : 1;
    }

    vector<int> sm_b; // x < x_top && y < y_top
    vector<int> gr_b; // x >= x_top && y >= y_top
    vector<int> sm_x; // x < x_top && y >= y_top
    vector<int> sm_y; // x >= x_top && y < y_top

    for (int i = 0; i < n; ++i) {
        if (xside[i] && yside[i]) {
            gr_b.push_back(i+1);
        } else if (!xside[i] && !yside[i]) {
            sm_b.push_back(i+1);
        } else if (!xside[i] && yside[i]) {
            sm_x.push_back(i+1);
        } else {
            sm_y.push_back(i+1);
        }
    }

    assert(sm_b.size() == gr_b.size());
    assert(sm_x.size() == sm_y.size());

    for (int i = 0; i < (int)gr_b.size(); ++i) {
        cout << gr_b[i] << ' ' << sm_b[i] << '\n';
    }

    for (int i = 0; i < (int)sm_x.size(); ++i) {
        cout << sm_x[i] << ' ' << sm_y[i] << '\n';
    }
}
