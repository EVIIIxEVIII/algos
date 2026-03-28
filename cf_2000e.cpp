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

    long long seen = 0;
    long long ans = 0;
    int j = 0;

    for (int i = 1; i <= k; ++i) {
        if (2 * (k - i) >= min(m, n)) continue;

        long long multiplier = k * (k - i + 1);
        long long count = (m - 2*(k - i)) * (n - 2*(k - i)) - seen - (i == k ? 4 : 0);
        seen += count;

        while (count > 0 && j < w) {
            ans += multiplier * a[j];
            count--;
            j++;
        }
    }

    for (int i = j; i < w; ++i) {
        ans += a[i];
    }

    cout << ans << '\n';
}
