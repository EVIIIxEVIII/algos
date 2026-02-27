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

    int max_val = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] == max_val;
    }

    cout << ans << '\n';
}
