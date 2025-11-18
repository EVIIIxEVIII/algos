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

        for (int i = 0; i < n; ++i) {
            for (long long j = 3; j <= a[i]; j+=2) {
                if (a[i] % j != 0) {
                    ans = min(j, ans);
                    break;
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
