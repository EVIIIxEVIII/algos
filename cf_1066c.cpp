#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> c(q);
        vector<int> l(q);
        vector<int> r(q);

        for (int i = 0; i < q; ++i) {
            cin >> c[i];
            cin >> l[i];
            cin >> r[i];
        }

        vector<int> ans(n+1, -1);

        vector<int> minMap(n+1, false);
        vector<int> mexMap(n+1, false);

        for (int i = 0; i < q; ++i) {
            if (c[i] == 1) {
                for (int j = l[i]; j <= r[i]; ++j) {
                    minMap[j] = true;
                }
            } else if (c[i] == 2) {
                for (int j = l[i]; j <= r[i]; ++j) {
                    mexMap[j] = true;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (minMap[i] && mexMap[i]) {
                ans[i] = k+1;
            } else if (mexMap[i]) {
                // important invariant for mex here:
                // if we have a continuous mex sequence of length >= k
                // in the array, then doing i % k will provably results in that
                // sequence having all the number from 0 to k - 1, just because of the
                // cycle being of length k
                ans[i] = i % k;
            } else {
                ans[i] = k;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
