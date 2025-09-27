#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<array<int, 2>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i][0];
        }

        for (int i = 0; i < n; ++i) {
            cin >> a[i][1];
        }


        long long ans = LLONG_MIN;
        long long totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += max(a[i][0], a[i][1]);
        }

        for (int i = 0; i < n; ++i) {
            ans = max(ans, totalSum + min(a[i][0], a[i][1]));
        }

        cout << ans << '\n';
    }
    return 0;
}
