#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<vector<int>> a(n, vector<int>(0));

        int k_max = 0;

        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            k_max = max(k_max, m);
            a[i].resize(m);

            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        vector<int> dp(k_max);

        for (int i = 0; i < k_max; ++i) {
            vector<int> ok;
            for (int j = 0; j < n; ++j) {
                if (a[j].size() >= i+1) ok.push_back(j);
            }

            int bestIdx = -1;
            int bestVal = INT_MAX;
            for (int j : ok) {
                int val = a[j][i];
                if (val < bestVal || (val == bestVal && (bestIdx == -1 || a[j].size() < a[bestIdx].size()))) {
                    bestVal = val;
                    bestIdx = j;
                }
            }

            dp[i] = bestIdx;
        }

        for (int i = 0; i < k_max; ++i) {
            int idx = dp[i];

            for (int j = i; j < a[idx].size(); ++j) {
                cout << a[idx][j] << ' ';
            }

            i += a[idx].size() - 1;
        }

        cout << '\n';
    }

    return 0;
}
