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
    int n;
    cin >> n;

    vector<int> a(n);
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 100) {
            ans = true;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}
