#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> cnt(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }

        vector<int> pref(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] + cnt[i];
        }

        int ans = 1;


        // main take away from the proble:
        // if the condition include 1 <= a_i <= n then the question
        // "how many numbers greater/less than x are there in the array"
        // can be answered using a cnt vector with a prefix sum on it

        for (int i = 1; i <= n; ++i) {
            int t = min(n, 4 * i - 1);
            int good = n - pref[t];

            good += cnt[i];

            if (2 * i <= n) good += cnt[2 * i];
            if (3 * i <= n) good += cnt[3 * i];

            if (good >= n - k) ans = i;
        }

        cout << ans << '\n';
    }
    return 0;
}
