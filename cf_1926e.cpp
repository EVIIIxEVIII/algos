#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

      ;
     ;;;
    ;;;;;
   ;;;;;;;
  ;;;;;;;;;
 ;;;;;;;;;;;
;;;;;;;;;;;;;
void solve() {
    long long n, k;
    cin >> n >> k;
    // the number of odd number will be (n + 1) / 2,
    // the number of numbers obtained through 2 is n / 4
    // odd numbers can be skipped, because they don't add any cards
    // past some point we only multiply by 1 because x*3 > n

    long long used = 0;
    long long fac = 1;

    while (true) {
        // number of numbers which become odd after division by fac.
        // if something is divisible by fac * 2 it is divisible by 2 so it is not odd after division by fac.
        long long cnt = n / fac - n / (fac << 1);
        if (used + cnt >= k) {
            long long pos = k - used;
            cout << fac * (2 * pos - 1) << '\n';
            return;
        }
        used += cnt;
        fac <<= 1;
    }
}
