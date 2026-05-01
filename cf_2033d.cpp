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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // for some segment [l, r] if the sum of [l, r] = 0, then either [l, r] can
    // be split into multiple segments such that [l1, r1] + [l2, r2] + ... = 0
    // or it cannot be split like that.


    long long pref = 0;
    set<long long> seen;
    seen.insert(0);

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        pref += a[i];

        if (seen.contains(pref)) {
            ans++;
            seen.clear();
            seen.insert(0);
            pref = 0;
        } else {
            seen.insert(pref);
        }
    }

    cout << ans << '\n';
}
