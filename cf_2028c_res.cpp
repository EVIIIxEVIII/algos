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

        vector<long long> prefix(n+1, 0);
        vector<long long> suffix(n+1, 0);

        int current_pref = 0;
        for (int i = 0; i < n; ++i) {
            current_pref += a[i];

            prefix[i + 1] = prefix[i];
            if (current_pref >= v) {
                prefix[i + 1]++;
                current_pref = 0;
            }
        }

        int current_suffix = 0;
        for (int i = n - 1; i >= 0; --i) {
            current_suffix += a[i];

            suffix[i] = suffix[i + 1];
            if (current_suffix >= v) {
                suffix[i]++;
                current_suffix = 0;
            }
        }

        vector<long long> prefix_sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
        }

        long long ans = -1;
        for (int l = 0; l <= n; ++l) {
            int left = prefix[l];
            int target = m - left;

            if (target < 0) continue;
            int r = upper_bound(suffix.begin() + l, suffix.end(), target, greater<int>{}) - suffix.begin() - 1;

            if (target == 0) r = n;

            if (r >= l) {
                ans = max(ans, prefix_sum[r] - prefix_sum[l]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
