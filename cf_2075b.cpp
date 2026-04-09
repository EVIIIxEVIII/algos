#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == 1) {
        cout << max(
            *max_element(a.begin(), a.end()-1) + a[n-1],
            *max_element(a.begin()+1, a.end()) + a[0]
        ) << '\n';
        return;
    }

    long long ans = 0;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < min(k+1, n); ++i) {
        ans += a[i];
    }

    cout << ans << '\n';
}
