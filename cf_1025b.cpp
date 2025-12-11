#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;

        if (n == m && n == 1) {
            cout << 0 << '\n';
        }

        long long topCut = n - a + 1;
        long long bottomCut = a;
        long long leftCut = b;
        long long rightCut = m - b + 1;

        long long cases[4][2] = {
            {topCut, m},
            {bottomCut, m},
            {n, leftCut},
            {n, rightCut},
        };

        int ans = n + m;
        for (auto [n, m] : cases) {
            int localAns = 0;
            while (n > 1) {
                n = (n + 1) / 2;
                localAns++;
            }

            while (m > 1) {
                m = (m + 1) / 2;
                localAns++;
            }

            ans = min(localAns, ans);
        }

        cout << ans + 1 << '\n';
    }
    return 0;
}
