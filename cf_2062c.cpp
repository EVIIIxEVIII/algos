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

    long long ans = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }

    while (a.size() > 1) {
        vector<long long> b;

        for (int i = 1; i < (int)a.size(); ++i) {
            b.push_back(a[i] - a[i - 1]);
        }

        long long current = 0;
        for (long long x : b) {
            current += x;
        }

        ans = max(ans, abs(current));
        a = std::move(b);
    }

    cout << ans << '\n';
}
