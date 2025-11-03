#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid(n);

        bool ans = true;
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        long long maxSum = LLONG_MIN;
        long long minSum = LLONG_MAX;

        long long maxDiff = LLONG_MIN;
        long long minDiff = LLONG_MAX;

        long long maxX = LLONG_MIN;
        long long minX = LLONG_MAX;

        long long maxY = LLONG_MIN;
        long long minY = LLONG_MAX;

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < n; ++j) {
                if (grid[i][j] == '#') {
                    maxSum = max(maxSum, i + j);
                    minSum = min(minSum, i + j);

                    maxDiff = max(maxDiff, i - j);
                    minDiff = min(minDiff, i - j);

                    maxX = max(maxX, i);
                    minX = min(minX, i);

                    maxY = max(maxY, j);
                    minY = min(minY, j);
                }
            }
        }

        if (maxSum - minSum <= 1 || maxDiff - minDiff <= 1 || (maxX - minX <= 1 && maxY - minY <= 1)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
