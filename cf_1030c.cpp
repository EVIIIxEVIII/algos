#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long k; cin >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = 0;
        long long p = 0;

        for (int p = 0; p < 63; ++p) {
            for (int i = 0; i < n; ++i) {
                bool isSet = (a[i] >> p) & 1;

                if (!isSet && (1LL << p) <= k) {
                    k -= (long long)(1LL << p);
                    ans++;
                } else if (isSet) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
