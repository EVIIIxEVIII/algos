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

    sort(a.begin(), a.end());

    if (a[0] != 0) {
        cout << 0 << '\n';
        return;
    }

    long long ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]+1) {
            ans++;
        } else if (a[i] != a[i-1]+1 && a[i] != a[i-1]) {
            break;
        }
    }

    cout << min(k-1LL, ans) << '\n';
}
