#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());



        vector<int> cnt(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }

        int maxMex = 0;
        while (maxMex <= n && cnt[maxMex] > 0) maxMex++;

        // missed point:
        // O(n) addition to a [L, R] region can be implemented
        // using prefix sums like this:
        vector<int> diff(n+2, 0);
        for (int i = 0; i <= maxMex; ++i) {
            int L = cnt[i];
            int R = n - i;

            if (L <= R) {
                diff[L]++;
                diff[R+1]--;
            }
        }

        vector<int> ans(n+1, 0);
        int cur = 0;

        for (int i = 0; i <= n; ++i) {
            cur += diff[i];
            ans[i] = cur;
        }

        for (int i = 0; i <=n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
