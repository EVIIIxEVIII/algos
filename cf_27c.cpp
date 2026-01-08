#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        set<int> used_nums;

        vector<int> ans(n+1, 0);
        if (n % 2 == 1) {
            int l = n & -n;
            ans[n] = n;
            used_nums.insert(n);
            ans[n-1] = n - l;
            used_nums.insert(n - l);
            ans[n-2] = l + (l == 1 ? 2 : 1);
            used_nums.insert(ans[n-2]);
            ans[n-3] = l;
            used_nums.insert(l);
        } else {
            if ((n & (n-1)) == 0) {
                ans[n] = n; // or
                ans[n-1] = n - 1; // and
                ans[n-2] = n - 2; // or
                ans[n-3] = 3; // and
                ans[n-4] = 1; // or
                used_nums.insert(ans[n]);
                used_nums.insert(ans[n-1]);
                used_nums.insert(ans[n-2]);
                used_nums.insert(ans[n-3]);
                used_nums.insert(ans[n-4]);
            } else {
                int h = 1 << (31 - __builtin_clz(n));
                ans[n] = h - 1;
                used_nums.insert(ans[n]);
                ans[n-1] = n - 1;
                used_nums.insert(ans[n-1]);
                ans[n-2] = n;
                used_nums.insert(ans[n-2]);
            }
        }

        int num = 1;
        for (int i = 1; i <= n; ++i) {
            while (used_nums.count(num)) num++;
            if (!ans[i]) {
                ans[i] = num++;
            }
        }

        int ansK = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                ansK &= ans[i];
            } else {
                ansK |= ans[i];
            }
        }

        cout << ansK << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
