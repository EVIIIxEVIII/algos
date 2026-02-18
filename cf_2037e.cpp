#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, v;
        cin >> n >> m >> v;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // idea: construct a prefix sum of the maximum number of sections that can be
        // constructed with score > v, then for every i binary search for a j such that prefix[i] + prefix[j] = m
        // and use a prefix sum on the array to compute the answer.

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<long long> prefix_sum(n+1);

        prefix[0] = a[0] >= v ? 1 : 0;

        int current_pref = a[0] >= v ? 0 : a[0];
        for (int i = 1; i < n; ++i) {
            current_pref += a[i];
            prefix[i] = prefix[i-1];
            if (current_pref >= v) {
                prefix[i]++;
                current_pref = 0;
            }
        }

        suffix[n-1] = a[n-1] >= v ? 1 : 0;
        int current_suf = a[n-1] >= v ? 0 : a[n-1];

        for (int i = n - 2; i >= 0; --i) {
            current_suf += a[i];

            suffix[i] = suffix[i+1];
            if (current_suf >= v) {
                suffix[i]++;
                current_suf = 0;
            }
        }

        prefix_sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + a[i-1];
        }

        long long ans = -1;
        for (int i = 0; i < n; ++i) {
            int left = i > 0 ? prefix[i - 1] : 0;
            int target = m - left;
            if (target < 0) continue;

            auto it = upper_bound(suffix.begin() + i, suffix.end(), target, greater<int>{});
            int j = it - suffix.begin() - 1;
            if (target == 0) j = n;

            if (j >= i) {
                ans = max(ans, prefix_sum[j] - prefix_sum[i]);
            }
        }

        cout << ans << '\n';

    }

    return 0;
}
