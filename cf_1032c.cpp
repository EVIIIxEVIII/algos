#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));

        int maxNum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = 0; cin >> x;
                mat[i][j] = x;
                maxNum = max(maxNum, x);
            }
        }

        vector<int> r(n);
        vector<int> c(m);
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == maxNum) {
                    r[i]++;
                    c[j]++;
                    total++;
                }
            }
        }

        bool flag = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (r[i] + c[j] - (mat[i][j] == maxNum) == total) {
                    flag = 1;
                }
            }
       }

        cout << maxNum - flag << '\n';
    }

    return 0;
}

