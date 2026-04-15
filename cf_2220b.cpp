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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    int max_in_row = 1;
    int in_row = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            in_row++;
        } else {
            max_in_row = max(max_in_row, in_row);
            in_row = 1;
        }
    }

    max_in_row = max(in_row, max_in_row);

    if (max_in_row < m) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
