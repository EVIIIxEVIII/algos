#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;

        if (a < b) {
            swap(a, b);
            swap(x, y);
        }

        if (x < y) {
            int ap = (max(0, (k - a + 1)) + x - 1) / x;
            int bp = (max(0, (k - ap*x) - b + 1) + y - 1) / y;

            cout << ap + bp << '\n';
        } else {
            int bp = (max(0, (k - b + 1)) + y - 1) / y;
            cout << bp << '\n';
        }
    }

    return 0;
}
