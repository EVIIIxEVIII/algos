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
    int n, k; cin >> n >> k;

    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum%2 == 1 || (n*k)%2 == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
