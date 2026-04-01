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

    vector<long long> suffix(n);
    suffix[n-1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i+1] + -a[i+1];
    }

    vector<long long> prefix(n);
    prefix[0] = 0;
    prefix[1] = a[0];
    for (int i = 2; i < n; ++i) {
        prefix[i] = prefix[i-1] + abs(a[i-1]);
    }

    long long ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, prefix[i] + suffix[i] * 1LL);
    }

    cout << ans << '\n';
}
