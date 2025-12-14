#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> perm(n+1, vector<int>(k));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            perm[a[i][j]][i] = j;
        }
    }

    vector<int> dp(n+1, 1);

    for (int i = 0; i < n; ++i) {
        int val = a[0][i];

        for (int j = 1; j <= n; ++j) {
            bool flag = true;
            for (int l = 0; l < k; ++l) {
                if (perm[j][l] >= perm[val][l]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                dp[val] = max(dp[val], dp[j] + 1);
            }
        }

    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(dp[i], ans);
    }

    cout << ans << '\n';

    return 0;
}
