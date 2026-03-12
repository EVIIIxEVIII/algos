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
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n+2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n+1] = l;

    // probably a b-search problem, but how do I do the check function?
    // probably not even a b-search problem because the check requires you to know
    // the best strategy already.

    // at each step you can either divide between all the cells or add the distance to a single cell

    long long ans = 0;
    vector<int> d(m);
    for (int i = 1; i <= n+1; ++i) {
        int max_val_before = 0;

        int per = (a[i] - a[i-1]) / m;
        int rem = (a[i] - a[i-1]) % m;

        for (int j = 0; j < m; ++j) {
            max_val_before = max(d[j], max_val_before);
            d[j] += per;
        }

        for (int j = 0; j < m; ++j) {
            if (d[j] < max_val_before + per && rem > 0) {
                d[j] += 1;
                rem--;
            }
        }

        for (int j = 0; j < rem; ++j) {
            d[j]++;
        }

        int max_j = 0;
        int max_val_after = 0;
        for (int j = 0; j < m; ++j) {
            if (max_val_after < d[j]) {
                max_val_after = d[j];
                max_j = j;
            }
        }

        d[max_j] = 0;
        ans = max(max_val_before * 1LL + a[i], ans);
    }

    cout << ans << '\n';
}
