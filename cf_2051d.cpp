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
    long long n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i< n; ++ i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long without = sum - a[i];

        if (without < x) {
            continue;
        }

        long long min_v = max(0LL, without - y);
        long long max_v = without - x;

        long long cnt = upper_bound(a.begin(), a.end(), max_v) - lower_bound(a.begin(), a.end(), min_v);

        if (min_v <= a[i] && a[i] <= max_v) {
            cnt--;
        }

        ans += cnt;
    }

    cout << ans / 2 << '\n';
}
