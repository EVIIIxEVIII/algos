#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int m; cin >> m;

        vector<int> sets_map(m+1, 0);
        vector<vector<int>> sets(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int k = 0; cin >> k;
            sets[i].resize(k);

            for (int j = 0; j < k; ++j) {
                cin >> sets[i][j];
                sets_map[sets[i][j]]++;
            }
        }

        bool valid = true;
        int non_unique_sets = 0;

        for (int i = 1; i <= m; ++i) {
            if (!sets_map[i]) {
                valid = false;
            }
        }

        if (!valid) {
            cout << "NO" << '\n';
            continue;
        }

        for (int i = 0; i < n; ++i) {
            bool is_unique = false;

            for (int j = 0; j < sets[i].size(); ++j) {
                if (sets_map[sets[i][j]] == 1) {
                    is_unique = true;
                    break;
                }
            }

            if (!is_unique) {
                non_unique_sets++;
            }
        }

        cout << (non_unique_sets >= 2 ? "YES" : "NO") << '\n';
    }
    return 0;
}
