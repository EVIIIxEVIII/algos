#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<long long> a(n+1);
        vector<long long> b(n+1);

        for (long long i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (long long i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        vector<long long> minNs(n+1);
        vector<long long> maxNs(n+1);

        minNs[0] = 0;
        maxNs[0] = 0;

        for (long long i = 1; i <= n; ++i) {
            long long minA = minNs[i-1] - a[i];
            long long minB = b[i] - maxNs[i-1];

            long long maxA = maxNs[i-1] - a[i];
            long long maxB = b[i] - minNs[i-1];

            minNs[i] = min({minA, minB, maxA, maxB});
            maxNs[i] = max({minA, minB, maxA, maxB});
        }

        cout << maxNs[n] << '\n';
    }
    return 0;
}
