#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // ok, so we have the array a, which tells us the number of black cells on each row
        // the second condition tells us that we have to use all of the columns or all of the rows
        // the third condition is more complicated, so on its own it behaves the same as the first one,
        // but together they make the problem complicated...

        // let's say we didn't have the third condition, then we could have computed the number of possible
        // configurations as just going through each row and doing
        // result *= a[i] choose n; and this should probably work...

        // now, let's consider the third condition
        // it somehows forces us to ignore the bottom part of the grid, because we have to both respect
        // the one cell per column and the second constraint.

        // so the y_i should contain all the numbers in [1, n]
        // until the first the y_i dominates from the third condition, after the half
        // the x_i dominates, because of the max(x_i, y_i) and max(x_i, n + 1 - y_i)

        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        if (sum != n) {
            cout << 0 << '\n';
            continue;
        }


    }
    return 0;
}
