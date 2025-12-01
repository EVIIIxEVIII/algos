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


        vector<int> ans(n, 0);

        int minVal = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] < minVal) {
                ans[i] = 1;
                minVal = a[i];
            }
        }

        int maxVal = INT_MIN;
        for (int i = n-1; i >= 0; --i) {
            if (a[i] > maxVal) {
                ans[i] = 1;
                maxVal = a[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i];
        }

        cout << '\n';
    }
    return 0;
}
