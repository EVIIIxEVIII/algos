#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n+2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // idea: if we have some a[i] such that a[i] is the maximum value in a
        // then we need at least a[i] decks to be built, as we cannot decrease the
        // number of cards of each type.
        //
        // idea: the answer is at least 1 and at most n, so [1, n]
        // idea: when a[i] == a[j] for all i and j, s.t i != j, then the answer is n.
        //
        // idea: the number of cards must be divisible by the answer. Let's denote
        // sum(a) as m, then m % ans == 0 and max(a) <= m / ans.

        long long m = 0;
        long long max_val = 0;
        bool is_n = true;

        for (int i = 1; i <= n; ++i) {
            max_val = max(max_val, a[i]);
            m += a[i];
            if (a[i] != a[i-1]) is_n = false;
        }

        long long left = 0;
        for (int i = 1; i <= n; ++i) {
            left += (max_val - a[i]);
        }

        if (is_n || left <= k) {
            cout << n << '\n';
            continue;
        }

        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            // m % ans == 0 and max(a) <= m / ans
            //
            // max(a) * ans <= m -> max condition
            // ((m + ans - 1) / s) * s -> divisibility condition
            //

            // max_val * i <= m + k
            // max_val * i - m <= k

            if ((i - (m % i)) % i <= k && max_val <= (m + k) / i) {
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
