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

        vector<int> floors(m);
        for (int i = 0; i < n; ++i) {
            floors[i] = a[i] / 100;
        }

        sort(floors.begin(), floors.end());

        for (int i = 0; i < n; i++) {
            int start = a[i];
            int end = a[n - 1 - i];

            if (i != n - i - 1) {
                bool flag = true;
                for (int j = 0; j < 6; ++j) {
                    cout << (flag ? start : end) << ' ';
                    flag = !flag;
                }

                flag = true;
                for (int j = 0; j < 6; ++j) {
                    cout << (flag ? end : start) << ' ';
                    flag = !flag;
                }
            } else {
                for (int j = 0; j < 6; ++j) {
                    cout << start << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
