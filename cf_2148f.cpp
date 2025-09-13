#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<vector<int>> a(n, vector<int>(0));

        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            a[i].resize(m);

            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        int maxLen = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (maxLen >= a[i].size()) {
                continue;
            }

            for (int j = maxLen; j < a[i].size(); ++j) {
                cout << a[i][j] << ' ';
            }

            maxLen = a[i].size();
        }

        cout << '\n';
    }

    return 0;
}
