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
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix(n+1);
    vector<long long> suffix(n+1);
    prefix[0] = 0;
    suffix[n] = 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            prefix[i] = prefix[i-1] + a[i];
        } else prefix[i] = prefix[i-1];
    }

    for (int i = n-1; i >= 0; --i) {
        if (a[i+1] < 0) {
            suffix[i] = suffix[i+1] + abs(a[i+1]);
        } else suffix[i] = suffix[i+1];
    }

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, suffix[i] + prefix[i]);
    }

    cout << ans << '\n';
}
