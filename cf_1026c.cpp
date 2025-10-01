#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> d(n);
        vector<array<int, 2>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> a[i][0];
            cin >> a[i][1];
        }

        vector<int> maxHeight(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            maxHeight[i] = min(maxHeight[i-1]+1, a[i-1][1]);
        }

        bool impossible = false;
        for (int i = 1; i <= n; ++i) {
            if (maxHeight[i-1] < a[i-1][0]) {
                impossible = true;
                break;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << maxHeight[i] << ' ';
        }
        cout << '\n';

        //if (impossible) {
        //    cout << -1 << '\n';
        //    continue;
        //}

    }
    return 0;
}
