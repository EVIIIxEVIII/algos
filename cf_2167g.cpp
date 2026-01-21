#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        // the final goal is to make the array such that for all i a[i] <= a[i+1] with minimum total cost

        // idea: reduce the proble to the question:
        // what monotonic subsequence do I keep so that all the elements I need to change have the smallest sum of c[i].

        // idea: reduce further:
        // what monotonic sequence has the greatest sum of c[i]?

        long long sum = 0;
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = c[i];
            sum += c[i];
        }

        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if (a[j] >= a[i]) {
                    dp[i] = max(dp[i], dp[j] + c[i]);
                }
            }
        }

        long long max_seq = 0;
        for (int i = 0; i < n; ++i) {
            max_seq = max(dp[i], max_seq);
        }

        cout << sum - max_seq << '\n';
    }
    return 0;
}
