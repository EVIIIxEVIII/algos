#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n == 0) {
            cout << "YES" << '\n';
            continue;
        }

        int digits = 32 - __builtin_clz(n);
        digits += digits%2;

        int side1 = 0;
        int side2 = 0;

        for (int i = 0; i < digits/2; ++i) {
            int cmp1 = ((n >> (digits - i - 1)) & 1);
            int cmp2 = ((n >> i) & 1);

            side1 += cmp1;
            side2 += cmp2;
        }

        cout << (side1 == side2 ? "YES" : "NO") << '\n';
    }
    return 0;
}
