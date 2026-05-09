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
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n);
    vector<int> b(k);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    // ok so after a reset (op 2) is done it makes no sense to execute operation 1 more than once in a row,
    // because the most amount of score we can get is 1.
    //
    // so we reset the ENTIRE array, this simplifies it a lot. So now we need to only find the best way
    // to collect the initial array, and then the previous statemnt holds.
    //
    // we can simulate the first n days, take the maximum possible score and then do res + (d - (n - took)) / 2?
    // the / 2 term is because in one day we add and in the next one we reset.

    int ans = 0;

    // 2*n because after 2*n days we are guaranteed to get 2*n/2 scores
    // and take <= n anyways.
    for (int i = 0; i < min(2*n, d); ++i) {
        int take = 0;

        for (int j = 0; j < n; ++j) {
            if (a[j] == j+1) {
                take++;
            }
        }

        ans = max(ans, take + (d - i - 1) / 2);

        for (int j = 0; j < b[i % k]; ++j) {
            a[j]++;
        }
    }

    cout << ans << '\n';
}
