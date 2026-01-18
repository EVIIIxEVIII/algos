#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // make take away from this problem:
        // mid = (l + r) / 2; l = mid + 1; r = mid - 1; -> exact search
        // mid = (l + r) / 2; l = mid + 1; r = mid;     -> lower bound (smallest value which has condition true)
        // mid = (l + r + 1) / 2; l = mid; r = mid - 1; -> upper bound (largest value which has condition true)

        long long total = n * (2LL * k + n - 1LL) / 2LL;

        long long l = 1;
        long long r = n;

        auto f = [&](long long x) {
            return (2*k - 1)*x + x*x - total;
        };

        while (l < r) {
            long long mid = (l + r) / 2;

            if (f(mid) < 0) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        long long best = llabs(f(r));
        if (r > 1) {
            best = min(best, llabs(f(r-1)));
        }

        cout << best << '\n';
    }

    return 0;
}
