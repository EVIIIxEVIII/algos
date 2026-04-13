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
    int n = 7;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int i = 0; i < n-1; ++i) {
        sum -= a[i];
    }

    sum += a[n-1];

    cout << sum << '\n';
}
