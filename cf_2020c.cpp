#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long b, c, d;
        cin >> b >> c >> d;

        // first idea:
        // (a | b) - (a & c) = d
        // for bit 1 being set we have either:
        // 1. (a | b) is set and (a & c) is not set
        // 2. (a | b) is not set and (a & c) is set (introduce borrow)
        //
        // 3. (a | b) set and (a & c) set makes it impossible
        // 4. (a | b) not set and (a & c) not set makes it impossible
        //
        // for bit 1 not being set we have either:
        // 1. (a | b) set and (a & c) set
        // 2. (a | b) not set and (a & c) not set
        //
        // 3. (a | b) set and (a & c) not set makes it impossible
        // 4. (a | b) not set and (a & c) set makes it impossible
        //
        // second idea:
        // 2. introduces borrows which is possible only when we have
        // (a | b) = 0 and (a & c) = 1. Now do we even care about this?
        // the answer is no, we don't because this case is not possible.
        // So now we can just implement this very basic algo.


        long long ans = 0;

        for (long long i = 0; i < 62; ++i) {
            long long d_bit = (1LL << i) & d;
            long long b_bit = (1LL << i) & b;
            long long c_bit = (1LL << i) & c;

            if (d_bit) {
                if (!c_bit) {
                    ans |= (1LL << i);
                } else if (b_bit && c_bit) {
                    ans |= (0LL << i);
                } else {
                    ans = -1;
                    break;
                }
            } else {
                if (c_bit) {
                    ans |= (1LL << i);
                } else if (!b_bit && !c_bit) {
                    ans |= (0LL << i);
                } else {
                    ans = -1;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
