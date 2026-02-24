#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        if (y < 0) {
            int r = x - abs(y) * 4;
            bool condition = (r % 3 == 0) && (r >= 0);

            cout << (condition ? "YES" : "NO") << '\n';
        } else if (y > 0) {
            int r = x - abs(y) * 2;
            bool condition = (r % 3 == 0) && (r >= 0);

            cout << (condition ? "YES" : "NO") << '\n';
        } else {
            cout << (x % 3 == 0 ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
