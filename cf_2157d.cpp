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

        // final idea: if we have a split w, we can construct this function f(x) = sum_{i=0}^{w-1}(x - a_i) + sum_{n-1}^{w+1}(a_i - x)
        // which can be evaluated at a point x, (it would answer the question: if the result is p, what would be the score given
        // the split at w). We take all the numbers before w and subtract a_i from x as if a_i was smaller than x, and then
        // compute the score on the remaining a_i as if they were larger.


        long long ans = 0;

        sort(a.begin(), a.end());

        long long S = a[0];
        vector<long long> prefix(n);
        vector<long long> sufix(n);

        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + a[i];
        }

        sufix[n-1] = a[n-1];
        for (int i = n - 2; i >= 0; --i) {
            sufix[i] = sufix[i+1] + a[i];
        }

        auto f = [&](long long x, long long w) {
            long long sum_left = (prefix[w] - a[w]);
            long long sum_rigth = (sufix[w] - a[w]);
            return (2LL*w - n + 1LL) * x + (sum_rigth - sum_left);
        };

        auto fnw = [&](long long x, long long w) { //no white
            long long sum_left = (w > 0) ? prefix[w-1] : 0LL;
            long long sum_rigth = (w < n) ? sufix[w] : 0LL;
            return (2LL*w - n) * x + (sum_rigth - sum_left);
        };

        long long best = 0;
        for (int w = 0; w < n; ++w) {
            best = max(best, min(f(l, w), f(r, w)));
        }

        for (int w = 0; w <= n; ++w) {
            best = max(best, min(fnw(l, w), fnw(r, w)));
        }

        cout << best << '\n';
    }

    return 0;
}
