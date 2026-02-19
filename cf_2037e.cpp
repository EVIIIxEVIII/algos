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

        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);
        vector<long long> prefix_sum(n+1);

        int current_pref = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i];
            current_pref += a[i];

            if (current_pref >= v) {
                prefix[i + 1]++;
                current_pref = 0;
            }
        }

        int current_suf = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1];
            current_suf += a[i];

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
        for (int l = 0, r = 0; l <= n; ++l) {

            while (r <= n && suffix[r] + prefix[l] >= m) {
                r++;
            }
            r--;

            if (r >= 0 && prefix[l] + suffix[r] >= m) {
                ans = max(ans, prefix_sum[r] - prefix_sum[l]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
