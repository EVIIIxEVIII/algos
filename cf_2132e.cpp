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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // some kind of b-search thing??
    // but the state space is like 1 2 3 4 3 2 1 type thing.

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    vector<long long> pa(n+1);
    vector<long long> pb(m+1);

    pa[0] = 0;
    pb[0] = 0;

    for (int i = 1; i <= n; ++i) {
        pa[i] = pa[i-1] + a[i-1];
    }

    for (int i = 1; i <= m; ++i) {
        pb[i] = pb[i-1] + b[i-1];
    }

    auto find_max = [&](int alim, int blim, int must) -> long long {
        int l = max(0, must - blim), r = min(alim, must);

        while (l < r) {
            int m = l + (r - l + 1) / 2;

            long long val = pa[m] + pb[max(must - m, 0)];
            long long prev_val = pa[m - 1] + pb[max(must - m + 1, 0)];

            if (prev_val < val) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return pa[l] + pb[max(must - l, 0)];
    };

    for (int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        cout << find_max(x, y, z) << '\n';
    }
}
