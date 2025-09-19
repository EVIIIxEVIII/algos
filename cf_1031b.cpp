#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int w, h, a, b;
        cin >> w >> h >> a >> b;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int distX = abs(x2 - x1);
        int distY = abs(y2 - y1);

        if (x1 != x2 && distX % a == 0) {
            cout << "YES" << '\n';
        } else if (y1 != y2 && distY % b == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
