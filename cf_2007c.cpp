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
    long long n; cin >> n;

    long long a, b;
    cin >> a >> b;

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // if we had only 1 number, say a, then the answer would be the maximum difference between
    // (c[i] % a - c[j] % a).

    long long mod = gcd(a, b);

    set<long long> groups;
    vector<long long> res(n);

    for (int i = 0; i < n; ++i) {
        res[i] = c[i] % mod;
    }

    sort(res.begin(), res.end());
    long long max_gap = 0;

    for (int i = 1; i < n; ++i) {
        max_gap = max(max_gap, res[i] - res[i-1]);
    }
    max_gap = max(max_gap, res[0] + mod - res[n-1]);

    cout << mod - max_gap << '\n';
}
