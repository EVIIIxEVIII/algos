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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    vector<int> ks;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (n / i != i) {
                ks.push_back(n/i);
            }
            ks.push_back(i);
        }
    }

    sort(ks.begin(), ks.end());

    int ans = 0;
    for (int k : ks) {
        int common = 0;

        for (int r = 0; r < k; ++r) {
            int g = 0;

            for (int j = r + k; j < n; j += k) {
                g = gcd(g, abs(a[j] - a[r]));
            }

            common = gcd(g,common);
        }

        if (common != 1) {
            ans++;
        }
    }

    cout << ans << '\n';
}
