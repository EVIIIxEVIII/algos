#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;

        if (b != 0) {
            long long x = n - 1 - c;
            long long k;
            if (x >= 0) k = x / b;
            else k = - ((-x + b - 1) / b);

            long long top_bound = max(0ll, k + 1);
            top_bound = min(top_bound, n);

            cout << n - top_bound << '\n';
        } else {
            if (c >= n) {
                cout << n << '\n';
            } else if (c >= n - 2) {
                cout << n - 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
