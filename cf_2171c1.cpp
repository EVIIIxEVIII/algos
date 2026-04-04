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
    vector<int> b(n);

    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total ^= a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        total ^= b[i];
    }

    if (total == 0) {
        cout << "Tie" << '\n';
        return;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            if (i % 2 == 0) {
                cout << "Ajisai" << '\n';
            } else {
                cout << "Mai" << '\n';
            }
            break;
        }
    }
}
