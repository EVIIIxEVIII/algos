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

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> suffix_gcd(n);
    suffix_gcd[n-1] = b[n-1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_gcd[i] = gcd(b[i], suffix_gcd[i+1]);
    }

    int ans = 1;
    for (int i = 0; i < n-1; ++i) {
        int overflow = b[i] / suffix_gcd[i];
        ans = lcm(ans, overflow);
    }

    cout << ans << '\n';
}
