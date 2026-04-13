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
    set<int> seen;

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (!seen.insert(a[i]).second) {
            possible = false;
        }
    }

    if (!possible) {
        cout << -1 << '\n';
        return;
    }

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
