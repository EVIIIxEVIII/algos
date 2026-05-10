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
    int n, q;
    cin >> n >> q;

    vector<int> d(q);
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
    }

    for (int i = 1; i <= n - 1; ++i) {
        cout << i << ' ' << i + 1 << '\n';
    }

    int cur_d = n - 1;

    for (int i = 0; i < q; ++i) {
        int dist = d[i];

        if (cur_d == dist) {
            cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
            continue;
        }

        cout << n << ' ' << cur_d << ' ' << dist << '\n';
        cur_d = dist;
    }
}
