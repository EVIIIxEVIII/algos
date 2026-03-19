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
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // idea for every cut check the number of ways using b-search
    // only half?

    long long ans = 0;
    for (int l = 1; l <= (n/2); ++l) {
        cout << l << ' ';
        // l <= r
        int r = n - l;

        int count_l = a.end() - lower_bound(a.begin(), a.end(), l);
        int count_r = a.end() - lower_bound(a.begin(), a.end(), r);

        // count_l * (count_r - 1)?
        ans += 2 * (count_l * count_r - count_r);
    }
    cout << '\n';

    cout << ans << '\n';
}

