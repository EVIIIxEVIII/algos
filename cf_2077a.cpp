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

    vector<int> a(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long target = a[0];
    long long inter = 0;

    for (int i = 1; i < 2*n - 1; i += 2) {
        inter += a[i] - a[i+1];
    }

    for (int i = 0; i < 2*n - 1; ++i) {
        cout << a[i] << ' ';
    }

    cout << target + abs(inter) + a[2*n - 1] << ' ';
    cout << a[2*n - 1] << '\n';
}
