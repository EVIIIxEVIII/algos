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

        // ok, so the new idea goes something like this:
        // we basically have a pyramid, but turned down
        // on the first row we can place the value in any cell, but we must put them in the
        // corners, because this is the only row which supports values (1, n) (n, 1)
        // and every other row suppors n - 2 values in the center
        // but you can place a value for some column at a row lower
        //
        // so the "rigid" configuration is when we have exactly 2 on each row besides the last
        // one where we have (n % 2 == 0) black cells
        //
        // ok, what's next?
        //
        // so if we have exactly 2 on each row, then we have the rigid case
        // buf if we have an additional one, we get some room for change
        // let's say we have the 5 by 5 case with 1 additional cell on the first row,
        // this means that we can move that cell 3 times
        // so if there is a free cell I can move it n - i*2 number of times
        // or more generall n - i*2 choose k (probably) where k is the number of these "free" cells we have on row i
        // but we might have a rigid configuration at the top of the pyramid, so we have to take into account that
        // so something like n - i*2 choose k - rigid cells, where k = 0
        //
        // but we know that we must have 2 cells on each row, besides the last one where it depends on the parity,
        // so if we have k cells on row i, then it means we have k less rows on the next few rows
        //
        // I don't know how to count these. I completely understand the problem.
        // We have a pyramid that is turned upside down and on each column we can choose any cell
        // the problem is the fixed number of rows, which dictates where what column we must select the cell in.

        long long sum = 0;
        for (int i = 0; i < (n+1)/2; ++i) {
            sum += a[i];
        }

        if (sum != n) {
            cout << 0 << '\n';
            continue;
        }

        bool ans = true;
        for (int i = 0; i < (n+1)/2; ++i) {
            if (a[i] > n - i*2) {
                ans = false; // row has more cells than the allowed
                break;
            }
        }

        if (!ans) {
            cout << 0 << '\n';
            continue;
        }

        cout << "Don't know" << '\n';
    }
    return 0;
}
