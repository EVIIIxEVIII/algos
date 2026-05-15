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
//dp with a prefix sum mb?
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int,int>> s;

    long long ans = 0;
    long long cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.back().first == a[i] + 1) {
            cur -= n - s.back().second;
            s.pop_back();
        }

        s.push_back({ a[i], i });
        cur += n - i;
        ans += cur;
    }

    cout << ans << '\n';
}
