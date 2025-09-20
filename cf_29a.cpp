#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x < y) {
            cout << 2 << '\n';
        } else if (x - 1 > y && y > 1) {
            cout << 3 << '\n';
        } else {
            cout << -1 << '\n';
        }

    }
    return 0;
}
