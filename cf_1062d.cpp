#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2) {
                ans = 2;
                break;
            }
        }

        if (ans != -1) {
            cout << ans << '\n';
            continue;
        }

        ans = INT_MAX;

        // 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37 * 41 * 43 * 47 * 53 > 10^8
        // so the greatest possible answer is 53

        static long long primes[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 16; ++j) {
                if (a[i] % primes[j] != 0) {
                    ans = min(primes[j], ans);
                }
            }
        }

        if (ans == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
