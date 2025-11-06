#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> ans(n);
        if (k % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                ans[i] = n - 2;
            }
            ans[n-2] = n-1;
        } else {
            for (int i = 0; i < n; ++i) {
                ans[i] = n - 1;
            }

            ans[n-1] = n - 2;
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i]+1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
