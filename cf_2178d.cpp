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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    // so the maximum number we can get is n / 2, because we can just sort the numbers
    // and pair the higher numbers with a lower numbers, the lower numbers will be removed
    // and we will have the top half remaining.
    //
    // we are guaranteed to be able to get 1, because we can just pair numbers like [i, i + 1], and number i
    // will be removed after.
    //
    // so m in [1, n/2] is the easy construction, but the 0 case is more complicated.
    // for the first type of construction we can just compute a k, such that k / 2 = m => k = 2 * m and then n - k elemets
    // will have to be removed by using the [i, i+1] operation, the rest k elements will be partitioned using the lower/top
    // parition.
    //
    // for m = 0 we can sum starting from a[n - 2] + a[n - 3] + ... while this sum < a[n - 1] if their sum is >= a[n - 1] we
    // can use that subset to attack a[n - 1] after we removed the prefix elves with the second type of move.

    if (m > n / 2) {
        cout << -1 << '\n';
        return;
    }

    auto pr = [&](const vector<pair<int,int>>& v) {
        cout << (int)v.size() << '\n';
        for (auto [x, y] : v) {
            cout << x << ' ' << y << '\n';
        }
    };

    sort(a.begin(), a.end());

    if (m == 0) {
        vector<pair<int,int>> ans;
        long long sum = 0;
        int start = -1;

        for (int i = n - 2; i >= 0; --i) {
            sum += a[i].first;
            if (sum >= a[n - 1].first) {
                start = i;
                break;
            }
        }

        if (start == -1) {
            cout << -1 << '\n';
            return;
        }

        for (int i = 0; i < start; ++i) {
            ans.push_back({ a[i].second, a[i + 1].second });
        }

        for (int i = start; i < n - 1; ++i) {
            ans.push_back({ a[i].second, a[n - 1].second });
        }
        pr(ans);
        return;
    }

    vector<pair<int,int>> ans;

    long long k = 2 * m;
    long long d = n - k;

    for (int i = 0; i < d; ++i) {
        ans.push_back({ a[i].second, a[i + 1].second });
    }

    for (int i = 0; i < m; ++i) {
        ans.push_back({ a[d + m + i].second, a[d + i].second });
    }

    pr(ans);
}
