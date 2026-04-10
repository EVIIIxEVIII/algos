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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == n) {
        for (int i = 1; i < n; i+=2) {
            if (a[i] != i/2+1) {
                cout << i/2+1 << '\n';
                return;
            }
        }
        cout << n/2 + 1 << '\n';
        return;
    }

    int free_moves = n-k;
    for (int i = 1; i <= free_moves+1; ++i) {
        if (a[i] != 1) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 2 << '\n';
}
