#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // main idea:
        // xor is a commutative operation, and in this problem xoring all the elements
        // results in the xor of the two answers, which itself tells us the bits in which the
        // answers are different. We can then use this information to check which person gets that highest
        // bit.
        //
        // side note: if a bit is set to 0 in diff, then no matter what you do and how you swap the a_i with b_i
        // it is impossible to have that bit differ in either answer.

        vector<int> a(n);
        vector<int> b(n);

        int diff = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            diff ^= a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            diff ^= b[i];
        }

        if (diff == 0) {
            cout << "Tie" << '\n';
            continue;
        }

        int hsb = 31 - __builtin_clz(diff);

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if ((a[i] ^ b[i]) & (1 << hsb)) {
                ans = i;
                break;
            }
        }

        cout << (ans % 2 ? "Mai" : "Ajisai") << '\n';
    }
    return 0;
}
