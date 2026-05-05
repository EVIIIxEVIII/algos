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

    // 1 - for rows
    // 2 - for cols
    long long sum = 2 * n * (n + 1) * (2 * n + 1) / 6 - n * (n + 1) / 2;

    cout << sum  << ' ' << 2*n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << 1 << ' ' << i << ' ';
        for (int j = n; j >= 1; --j) {
            cout << j << ' ';
        }
        cout << '\n';

        cout << 2 << ' ' << i << ' ';
        for (int j = n; j >= 1; --j) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
