#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n <= 60 && (1ll << (n-1)) < k) {
            cout << -1 << '\n';
            continue;
        }

        k--;

        vector<int> a;
        while (k) {
            a.push_back(k%2);
            k /= 2;
        }

        while (a.size() < n-1) a.push_back(0);

        reverse(a.begin(), a.end());

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
