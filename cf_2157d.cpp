#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        // log(10^9) * n????


        // idea: worst cases are x = l and x = r.
        //
        // idea: if there is a bet a[i] such that abs(a[i] - l) > abs(a[i] - r) we have to make the best point towards
        // l and vice verse for r if (abs[i] - r) > abs(a[i] - l).
        //
        // idea: note that we can choose a split point S such that all elements in a[i], such that S > a[i] are turned to r
        // and all elements S < a[i] are turned to l.
        //
        // idea: we can probably binary search this point, and the condition is to maximize
        // b := sum(l - a[i]) such that S > a[i] and c := sum(r - a[i]) such that S < a[i] min(b, a);
        // which can probably done using prefix sums?

        long long ans = 0;

        sort(a.begin(), a.end());

        long long S = a[0];
        vector<long long> prefix(n);

        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + a[i];
            S += a[i];
        }






    }

    return 0;
}
