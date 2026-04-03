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
    long long n, k; cin >> n >> k;

    vector<long long> q(n);
    vector<long long> r(n);

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    sort(q.begin(), q.end());
    sort(r.begin(), r.end(), greater<long long>());

    long long ans = 0;
    int j = 0;
    for (int i = 0; i < n && j < n; ++i) {
        if ((r[i] + 1) * q[j] + r[i] <= k) {
            ans++;
            j++;
        }
    }

    cout << ans << '\n';
}
