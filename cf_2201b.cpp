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

    int first = (2*n - 1) - k;

    vector<int> ans;
    for (int i = 1; i <= first; ++i) {
        ans.push_back(i);
        ans.push_back(i);
    }

    int second = n - first;
    if (second == 1) {
        ans.push_back(first + 1);
        ans.push_back(first + 1);
    } else {
        ans.push_back(first + 1);
        ans.push_back(first + 2);

        for (int i = 3; i <= second; ++i) {
            ans.push_back(first + i);
            ans.push_back(first + i - 2);
        }

        ans.push_back(first + second - 1);
        ans.push_back(first + second);
    }

    for (int val : ans) {
        cout << val << ' ';
    }
    cout << '\n';
}

