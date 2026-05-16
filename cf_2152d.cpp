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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int,int>> rn(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        rn[i].first = l - 1;
        rn[i].second = r;
    }

    // we can easily compute the number of moves P will make for an interval [l, r] if R doesn't make any moves.
    //
    // maybe we can sort by "how close is a[i]" to its next power of 2?
    //
    // only differences of 1 matter? because R can't stack more than 2 moves in an a[i], because P can
    // destory that added 1 in the next move.
    //

    vector<long long> prefix_base(n+1);
    vector<long long> prefix_b(n+1);
    vector<long long> prefix_c(n+1);

    prefix_base[0] = 0;
    prefix_b[0] = 0;
    prefix_c[0] = 0;

    auto is_power_2 = [&](long long x) {
        return x > 0 && ((x & (x-1)) == 0);
    };

    for (int i = 1; i <= n; ++i) {
        long long x = a[i-1];
        prefix_base[i] = prefix_base[i-1] + (63 - __builtin_clzll(x));
        prefix_b[i] = prefix_b[i-1];
        prefix_c[i] = prefix_c[i-1];

        if (a[i-1] != 2 && is_power_2(a[i-1]-1)) {
            prefix_b[i]++;
        } else if (!is_power_2(a[i-1])) {
            prefix_c[i]++;
        }
    }

    for (int i = 0; i < q; ++i) {
        auto [l, r] = rn[i];

        long long val = prefix_base[r] - prefix_base[l];

        val += (prefix_b[r] - prefix_b[l]) / 2;
        val += prefix_c[r] - prefix_c[l];

        cout << val << '\n';
    }
}
