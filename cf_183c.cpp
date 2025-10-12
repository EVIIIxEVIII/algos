#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            char val; cin >> val;
            a[i] = val == 'a' ? 1 : -1;
            sum += a[i];
        }

        if (sum == 0) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> map(2*n + 1, INT_MIN);
        vector<int> prefix(n);

        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + a[i];
        }

        int ans = INT_MAX;
        int offset = n;
        map[offset] = -1;
        for (int r = 0; r < n; ++r) {
            int need = prefix[r] - sum + offset;

            if (map[need] != INT_MIN) {
                ans = min(ans, r - map[need]);
            }

            map[prefix[r] + offset] = r;
        }

        if (ans == n) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
