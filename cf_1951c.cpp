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
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < k / m; ++i) {
        ans += 1LL * m * (a[i] + i * m);
    }

    if (k%m > 0) {
        ans += 1LL * (k%m) * (a[k/m] + (k/m) * m);
    }

    // swapping the pairs doesn't matter, let "good" order be:
    // x*a[i] + y*(a[j] + x)
    // define the "bad" order as:
    // y*a[j] + x*(a[i] + y)
    // now compare:
    // xa[i] + ya[j] + yx - (ya[j] + xa[i] + xy) =
    // xa[i] + ya[j] + yx - ya[j] - xa[i] - xy = 0
    // so the order of the days you pick doesn't matter.

    cout << ans << '\n';
}
