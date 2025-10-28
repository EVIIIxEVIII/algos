#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int x, y, a; cin >> x >> y >> a;

        int pair = x + y;
        int pairsCount = a / (x + y);

        if ((x + y) * pairsCount + x >= (a+1)) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}
