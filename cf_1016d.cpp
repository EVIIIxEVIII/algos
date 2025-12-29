#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long q; cin >> q;

        for (long long i = 0; i < q; ++i) {
            string op;
            cin >> op;

            if (op == "->") {
                long long x, y;
                cin >> x >> y;

                x--;
                y--;

                long long ans = 0;
                for (long long i = 0; i < n; ++i) {
                    long long xb = (x >> i) & 1;
                    long long yb = (y >> i) & 1;

                    long long v = 0;
                    if (xb && yb) v = 1;
                    else if (xb)  v = 2;
                    else if (yb)  v = 3;

                    ans |= (v << (2 * i));
                }

                cout << ans + 1 << '\n';
            } else if (op == "<-") {
                long long val = 0;
                cin >> val;

                val--;
                long long x = 0, y = 0;

                for (long long i = 0; i < n; ++i) {
                    long long idx = (val >> (2 * i)) & 3;
                    if (idx == 1) x |= 1 << i, y |= 1 << i;
                    if (idx == 3) x |= 1 << i;
                    if (idx == 2) y |= 1 << i;
                }

                cout << y + 1 << ' ' << x + 1 << '\n';
            }
        }
    }
    return 0;
}
