#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // key point: the next row should be a "shift" of the prior one

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        cout << (n-2)*2 + 1 << '\n';

        cout << 1 << ' ' << 1 << ' ' << n << '\n';
        cout << 2 << ' ' << 2 << ' ' << n << '\n';

        for (int i = 3; i < n; ++i) {
            cout << i << ' ' << 1 << ' ' << i-1 << '\n';
            cout << i << ' ' << i << ' ' << n << '\n';
        }

        cout << n << ' ' << 1 << ' ' << n-1 << '\n';
    }
    return 0;
}
