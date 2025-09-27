#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k > pow(2, n-1)) {
            cout << -1 << '\n';
            continue;
        }

        k--;

        vector<int> a(n-1);
        for (long long i = n - 2; i >= 0; --i) {
            long long bit = (k >> (n - 2 - i)) & 1;
            a[i] = bit;
        }

        int l = 0, r = n-1;
        vector<int> ans(n);

        for (int i = 0; i < n-1; i++) {
            if (a[i]) {
                ans[r] = i+1;
                r--;
            } else {
                ans[l] = i+1;
                l++;
            }
        }

        ans[l] = n;

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
