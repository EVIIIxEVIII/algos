#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int l = 0, r = m - 1;

        for (int i = n % 2; i < n; i+=2) {
            bool flag = true;
            for (int j = 0; j < 6; ++j) {
                cout << (flag ? a[l] : a[r]) << ' ';
                flag = !flag;
            }

            cout << '\n';

            flag = true;
            for (int j = 0; j < 6; ++j) {
                cout << (flag ? a[r] : a[l]) << ' ';
                flag = !flag;
            }

            cout << '\n';

            l++;
            r--;
        }

        if (n % 2) {
            bool flag = true;
            for (int j = 0; j < 6; ++j) {
                cout << (flag ? a[l] : a[r]) << ' ';
                flag = !flag;
            }
            cout << '\n';
        }

    }

    return 0;
}
