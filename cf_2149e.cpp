#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        // main idea 1: you do not use prefix sums on unique elements
        // main idea 2: to compute the number of elements in an intersection you do:
        // min(r1, r2) - max(l1, l2) + 1
        // main idea 3: when you have unique elements in an array, you can normalize them
        // by sorting, erasing non unique elements and then for each element
        // in the original array we set it to the index inside the sorted unique array.

        vector<int> vals = a;
        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        }

        int disy= 0;
        int disx = 0;

        vector<int> cnty(n+1, 0);
        vector<int> cntx(n+1, 0);

        long long ans = 0;
        int x = 0;
        int y = 0;

        for (int i = 0; i < n; ++i) {
            // [i, x) the first segment that has exactly k unique elements
            while (disx < k && x < n) {
                if (cntx[a[x]] == 0) {
                    disx++;
                }

                cntx[a[x]]++;
                x++;
            }

            if (disx < k) {
                break;
            }

            // [i, y) the last segment that has exactly k unique elements
            while (y < n) {
                if (cnty[a[y]] == 0 && disy == k) {
                    break;
                }

                if (cnty[a[y]] == 0) {
                    disy++;
                }

                cnty[a[y]]++;
                y++;
            }

            if (--cnty[a[i]] == 0) {
                disy--;
            }

            if (--cntx[a[i]] == 0) {
                disx--;
            }

            // now for all j in [x-1, y-1] we have [i, j] has exactly k elements
            //
            // the answer is the number of elements in the intersection of:
            // [x-1, y-1] intersection [i + l - 1, i + r - 1]

            int left = max(x - 1, i + l - 1);
            int right = min(y - 1, i + r - 1);

            ans += max(0, right - left + 1);
        }

        cout << ans << '\n';
    }
    return 0;
}
