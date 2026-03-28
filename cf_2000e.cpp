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
    int n, m, k;
    int w;
    cin >> n >> m >> k >> w;

    vector<int> a(w);
    for (int i = 0; i < w; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    long long ans = 0;

    map<long long, long long> multipliers;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int rows = min(i, n - k) - max(i - k + 1, 0) + 1;
            int cols = min(j, m - k) - max(j - k + 1, 0) + 1;

            long long multiplier = rows * cols;
            multipliers[multiplier]++;
        }
    }

    int j = 0;
    for (auto it = multipliers.rbegin(); it != multipliers.rend(); ++it) {
        auto [m, c] = *it;
        while (j < w && c > 0) {
            ans += a[j] * m;
            j++;
            c--;
        }
    }

    cout << ans << '\n';
}
