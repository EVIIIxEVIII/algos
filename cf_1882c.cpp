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

    vector<long long> suffix(n + 1, 0);
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i+1] + max(0, a[i+1]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, ((i+1) % 2 ? a[i] : 0) + suffix[i]);
    }

    cout << ans << '\n';
}
