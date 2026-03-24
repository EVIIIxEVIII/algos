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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1] || a[i] == abs(a[i-1] - 7)) {
            ans++;
            i++;
        }
    }

    cout << ans << '\n';
}
