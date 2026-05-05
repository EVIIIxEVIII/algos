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

    if (n == 2) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else if (n == 3) {
        cout << 2 << ' ' << 1 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 3 << ' ' << 1 << '\n';
    } else {
        for (int i = 1; i <= n - 2; ++i) {
            cout << i << ' ' << i << '\n';
        }

        cout << n << ' ' << n - 1 << '\n';
        cout << n << ' ' << n << '\n';
    }

    cout << '\n';
}
