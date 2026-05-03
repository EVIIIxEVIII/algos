#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
    // the length of a good subarray can only be 3 + 2*k

    // let's unwrap the operation. We have:
    // (c1 - c2 + c3) - (c4 - c5 + c6) + (c7 - c8 + c9) =>
    // c1 - c2 + c3 - c4 + c5 - c6 + c7 - c8 + c9
    //
    // c1 - (c2 - c3 + c4) + c5 => c1 - c2 + c3 - c4 + c5
    // so it doesn't even matter the "order" in which we apply the operation
    //
    // what does it mean for c_i-1 + c_i+1 > c_i? it means that no subarray of size 3 has
    // sum <= 0.
    //
    // so a beautiful subarray [l, r) has prefix[r] - prefix[l] > 0?
    //
    // sliding window?
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    prefix[1] = a[1];

    for (int i = 2; i <= n; ++i) {
        prefix[i] = (i % 2 == 0 ? -1 : 1) * a[i] + prefix[i-1];
    }

    ordered_set<pair<long long,int>> odd_prev;
    ordered_set<pair<long long,int>> even_prev;

    even_prev.insert({0, 0});
    odd_prev.insert({prefix[1], 1});

    long long ans = 0;
    for (int r = 3; r <= n; ++r) {
        if (r % 2) {
            long long less = even_prev.order_of_key({ prefix[r], -1 });
            ans += less;

            even_prev.insert({ prefix[r-1], r-1 });
        } else {
            long long greater = odd_prev.size() - odd_prev.order_of_key({ prefix[r], INT_MAX });
            ans += greater;

            odd_prev.insert({ prefix[r-1], r - 1 });
        }
    }

    cout << ans + (long long)n << '\n';
}
