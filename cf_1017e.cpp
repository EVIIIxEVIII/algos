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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int minPopCount = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minPopCount = min(__builtin_popcount(a[i]), minPopCount);
        }

        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (__builtin_popcount(a[i]) == minPopCount) {
                k = max(k, a[i]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (a[i] ^ k);
        }

        cout << ans << '\n';
    }
    return 0;
}
