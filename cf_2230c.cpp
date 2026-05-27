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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    long long fixable = 0;
    long long to_be_fixed = 0;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 2) {
            cnt++;
            fixable += (a[i] - 2) / 2;
            ans += a[i];
        } else {
            to_be_fixed++;
        }
    }

    if (cnt == 1) {
        fixable += 1;
    }

    ans += min(fixable, to_be_fixed);

    if (ans < 3) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }
}
