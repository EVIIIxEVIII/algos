#include <bits/stdc++.h>
using namespace std;

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

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    multiset<int> see;
    int r = k;

    for (int i = r; i < n; ++i) {
        see.insert(h[i]);
    }

    int ans = INT_MAX;
    for (int l = 0; l < n && !see.empty(); ++l) {
        int val = h[l];

        auto it = see.lower_bound(val);
        if (it != see.end()) {
            ans = min(ans, abs(val - *it));
        }

        if (it != see.begin()) {
            auto pit = prev(it);
            ans = min(ans, abs(val - *pit));
        }

        auto rem = see.find(h[r]);
        if (rem != see.end()) {
            see.erase(rem);
        }
        r++;
    }

    cout << ans << '\n';
}
