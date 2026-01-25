#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> cnt(n+1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        // idea: it is not possible to decrease the existent number of palindromic subarrays, but it
        // is probably possible to keep that number the same.
        //
        // idea: we have 1 <= k <= n and we have 1 <= x <= n, so we can choose an unique number each time we append at the end and
        // that would for sure not create any palindromic subarrays in this new section from a[n] to a[n + k]
        //
        // idea: each time j we append a new number to the end it should be different from the number at a[n-j+1] and we cannot
        // repeat numbers
        //
        // refinement: we need to pick k unique numbers from [1, n] such that at each position i, we have a[n-i+1] != ans[i]
        //
        // idea: the second point in the refinment is wrong. In the case when all the numbers from a[1] till a[n] are
        // equal to some x we would be forced to have a[n-i+1] == ans[i], but that shouldn't be a problem unless we use
        // the number x at the position a[n+1] or a[n+2] ([3, 3, 3 | _, _, 3])
        //
        // final idea: only the first two elements are actually important after that we can just choose k - 2 unique elements and
        // we would be good to go, but the first two elements should be chosen such that el1 != a[n] && el != a[n-1] && el2 !=
        // a[n] && el2 != a[n-1]


        int x = -1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                x = i;
                break;
            }
        }

        if (x == -1) {
            for (int i = 0; i < k; ++i) {
                cout << a[i % 3] << ' ';
            }
        } else {
            int y = -1;
            int z = a[n-1];

            for (int i = 1; i <= n;  ++i) {
                if (i != x && i != z) {
                    y = i;
                    break;
                }
            }

            for (int i = 0; i < k; ++i) {
                if (i % 3 == 0) {
                    cout << x << ' ';
                } else if (i % 3 == 1) {
                    cout << y << ' ';
                } else {
                    cout << z << ' ';
                }
            }
        }

        cout << '\n';

    }

    return 0;
}
