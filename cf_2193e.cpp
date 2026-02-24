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

        vector<int> ans(n+1, 1e9);
        for (int i = 0; i < n; ++i) {
            ans[a[i]] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                // runs n / i times => sum of n / 1 + n / 2 + n / 3 => n * (1 + 1/2 + 1/3 + 1/4 + ...)
                // => n * log(n) not O(n^2)
                ans[j] = min(ans[j], ans[i] + ans[j / i]);
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << (ans[i] == 1e9 ? -1 : ans[i]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
