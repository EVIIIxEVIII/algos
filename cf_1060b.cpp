#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        int maxSoFar = a[0];

        for (int i = 1; i < n; ++i) {
            if (i%2) {
                a[i] = max(a[i], maxSoFar);
            }

            maxSoFar = max(maxSoFar, a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i%2) continue;

            int prev = i-1 >= 0 ? a[i-1] : INT_MAX;
            int next = i+1 < n ? a[i+1] : INT_MAX;

            int diff = a[i] - min(prev, next);

            if (diff >= 0) {
                ans += a[i] - min(prev, next) + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
