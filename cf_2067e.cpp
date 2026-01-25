#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // the main idea was to see that if we can have a minimal distance of m then we
        // can also have a minimal distance of m - 1, and so here we can easily binary search
        // on the value of m. Also, important idea: we can do O(n) inside a binary search, because
        // that is O(nlog(n))
        //
        // it probably can be solved with a max heap, but it would be more complex code for sure...

        // mid = (l + r) / 2; l = mid + 1; r = mid; finds the first point where the condition is false
        // mid = (l + r + 1) / 2; l = mid; r = mid - 1; finds the last point where the condition is true
        // mid = (l + r) / 2; l = mid + 1; r = mid - 1; finds the exact match

        a.push_back(1e9);
        a.push_back(-1e9);

        n += 2;

        sort(a.begin(), a.end());

        int l = 0;
        int r = x+1;

        //mid = (l + r) / 2; l = mid + 1; r = mid;
        while (l < r) {
            int m = (l + r + 1) / 2;

            a[0] = -m;
            a[n-1] = x + m;

            int f = 0;

            for (int i = 1; i < n; ++i) {
                f += max(0, (a[i] - m) - (a[i-1] + m) + 1);
            }

            if (f >= k) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        a[0] = -l;
        a[n-1] = x + l;

        int j = 0;
        for (int i = 1; i < n; ++i) {
            for (j = max(j, a[i-1] + l); j <= min((a[i] - l), x) && k; ++j) {
                std::cout << j << ' ';
                k--;
            }
        }

        cout << '\n';
    }

    return 0;
}
