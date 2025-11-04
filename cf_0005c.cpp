#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int l = 0, r = n - 1;

        long long s = 0;
        long long prev = 0;
        vector<int> ans;
        long long p = 0;

        while (l <= r) {
            if ((a[r] + s) / x > prev) {
                ans.push_back(a[r]);
                prev = (a[r] + s) / x;

                p += a[r];
                s += a[r];
                r--;
            } else {
                ans.push_back(a[l]);
                s += a[l];
                l++;
            }
        }


        cout << p << '\n';
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
