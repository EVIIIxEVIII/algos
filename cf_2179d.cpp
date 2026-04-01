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

    cout << (1 << n) - 1 << ' ';

    for (int i = n - 1; i >= 0; --i) {
        int num = (1 << i) - 1;

        cout << num << ' ';
        int cnt = (1 << (n - 1 - i)) - 1;

        for (int j = 1; j <= cnt; ++j) {
            int val = num | (j << (i+1));
            cout << val << ' ';
        }
    }

    cout << '\n';
}
