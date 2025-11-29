#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        // the idea here is that odds will add +1 in any case,
        // but the even number might add 2 or 0
        // we firstly consider the evens and then we put the odds at the
        // end to fill in the gaps

        vector<int> a(n*2);
        for (int i = 0; i < n*2; ++i) {
            cin >> a[i];
        }

        vector<int> b(n*2 + 1, 0);
        for (int i = 0; i < 2*n; ++i) {
            b[a[i]]++;
        }

        int even = 0;
        int odd = 0;
        for (int i = 1; i <= 2*n; ++i) {
            if (b[i] == 0) continue;
            if (b[i] % 2) {
                odd++;
            } else {
                even++;
            }
        }

        int ans = 0;
        if (odd > 0) {
            ans = odd + 2 * even;
        } else {
            if (n % 2 == 0) {
                if (even % 2 == 0) ans = even * 2; // so if n is even we have to have an even number of even counts
                // because the sum of an even number of odd numbers is even
                else ans = (even - 1) * 2;
            } else {
                if (even % 2 == 1) ans = even * 2; // same idea here: the sum of an odd number of odd numbers is odd
                else ans = (even - 1) * 2;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
