#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        vector<long long> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        bool ans = true;

        // basically what we have is a set of linear equations of the form
        // a * x + b * y = a[0]
        // c * x + d * y = a[1]
        // e * x + f * y = a[2]
        //
        // here x and y are the number of operations 1s and 2s repectively
        // so the general formula is
        // i * x + (n - i + 1) * y + a[i]
        //
        // we pick the first two equation and the last equation which get us this system:
        //
        // x + n * y = a[0]
        // n * x + y = a[n]
        //
        // x = a[0] - ny
        // and for then find the expression for y, find y and then find x

        if ((a[n] - n * a[1]) % (1 - n*n)) {
            cout << "NO" << '\n';
            continue;
        }

        int y = (a[n] - n * a[1]) / (1 - n*n);
        int x = a[1] - n * y;

        if (y < 0 || x < 0) {
            cout << "NO" << '\n';
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (i * x + y * (n - i + 1) != a[i]) {
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
