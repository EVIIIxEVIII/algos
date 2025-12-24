#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<array<long long, 2>> mon(n);
        for (long long i = 0; i < n; ++i) {
            cin >> mon[i][0] >> mon[i][1];
        }

        if (n <= 2) {
            cout << n << '\n';
            continue;
        }

        const long long INF = (long long)4e18;

        long long minX1 = INF, minX2 = INF, maxX1 = -INF, maxX2 = -INF;
        long long minY1 = INF, minY2 = INF, maxY1 = -INF, maxY2 = -INF;
        int cntMinX = 0, cntMaxX = 0, cntMinY = 0, cntMaxY = 0;

        for (auto &p : mon) {
            long long x = p[0], y = p[1];

            if (x < minX1) { minX2 = minX1; minX1 = x; cntMinX = 1; }
            else if (x == minX1) { cntMinX++; }
            else if (x < minX2) { minX2 = x; }

            if (x > maxX1) { maxX2 = maxX1; maxX1 = x; cntMaxX = 1; }
            else if (x == maxX1) { cntMaxX++; }
            else if (x > maxX2) { maxX2 = x; }

            if (y < minY1) { minY2 = minY1; minY1 = y; cntMinY = 1; }
            else if (y == minY1) { cntMinY++; }
            else if (y < minY2) { minY2 = y; }

            if (y > maxY1) { maxY2 = maxY1; maxY1 = y; cntMaxY = 1; }
            else if (y == maxY1) { cntMaxY++; }
            else if (y > maxY2) { maxY2 = y; }
        }

        long long ans = LLONG_MAX;

        for (auto &p : mon) {
            long long x = p[0], y = p[1];

            long long loX = (x == minX1 && cntMinX == 1) ? minX2 : minX1;
            long long hiX = (x == maxX1 && cntMaxX == 1) ? maxX2 : maxX1;
            long long loY = (y == minY1 && cntMinY == 1) ? minY2 : minY1;
            long long hiY = (y == maxY1 && cntMaxY == 1) ? maxY2 : maxY1;

            long long W = hiX - loX + 1;
            long long H = hiY - loY + 1;
            long long A = W * H;

            if (A == n - 1) {
                ans = min(ans, min((W + 1) * H, W * (H + 1)));
            } else {
                ans = min(ans, A);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

