#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        vector<long long> b(n);

        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (long long i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // only the first move is important

        vector<long long> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](long long i, long long j) {
            return min(a[i], b[i]) < min(a[j], b[j]);
        });

        long long minDist = INT_MAX;
        long long currentEnd = max(a[idx[0]], b[idx[0]]);

        for (long long i = 1; i < n; ++i) {
            long long l = min(b[idx[i]], a[idx[i]]);
            long long r = max(b[idx[i]], a[idx[i]]);

            if (l <= currentEnd) {
                minDist = 0;
                break;
            } else {
                minDist = min(minDist, l - currentEnd);
                currentEnd = max(currentEnd, r);
            }
        }

        long long ans = 0;
        for (long long i = 0; i < n; ++i) {
            ans += abs(a[i] - b[i]);
        }

        ans += minDist * 2;

        cout << ans << '\n';
    }
    return 0;
}
