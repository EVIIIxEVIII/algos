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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = LLONG_MAX;

    int l = 0;
    while (l < n) {
        int r = l;

        while (r + 1 < n && a[r + 1] == a[l]) {
            ++r;
        }

        long long len = r - l + 1;
        ans = min(ans, a[l] * (n - len));

        l = r + 1;
    }

    cout << ans << '\n';
}
