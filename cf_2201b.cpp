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
    int n, k;
    cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int x = k - n + 1;
    int fixed = n - x;

    vector<int> ans;

    for (int i = 1; i <= fixed; ++i) {
        ans.push_back(i);
        ans.push_back(i);
    }

    int base = fixed;

    if (x == 1) {
        ans.push_back(base + 1);
        ans.push_back(base + 1);
    } else {
        ans.push_back(base + 1);
        ans.push_back(base + 2);

        for (int i = 3; i <= x; ++i) {
            ans.push_back(base + i);
            ans.push_back(base + i - 2);
        }

        ans.push_back(base + x - 1);
        ans.push_back(base + x);
    }

    for (int v : ans) {
        cout << v << ' ';
    }

    cout << '\n';
}
