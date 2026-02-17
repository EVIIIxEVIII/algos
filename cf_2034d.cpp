#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        // idea: the first thing we could do is count the number of 0, 1 and 2 and denote these counts as a, b, c
        // then we would know that the first a positions should be 0, the next b should be 1 and the last c should be 2
        // idea: notice that 1s can be swapped with both 0s and 2s, so we should start with them and then we could use 1s
        // to swap 0s with 2s in 2 moves.

        int n;
        cin >> n;
        vector<int> a(n);
        int z = 0, o = 0, t = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) z++;
            if (a[i] == 1) o++;
            if (a[i] == 2) t++;
        }

        vector<pair<int, int>> ans;
        set<int> free_zeros;

        for (int i = 0; i < z; ++i) {
            if (a[i] != 1 && a[i] != 0) {
                free_zeros.insert(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] != 1 || i < z) continue;

            if (!free_zeros.empty()) {
                ans.push_back({ *free_zeros.begin() + 1, i + 1 });
                free_zeros.erase(*free_zeros.begin());
            } else break;
        }

        set<int> ones_pos;
        for (int i = 0, swapped = 0; i < n; ++i) {
            if (a[i] != 0) continue;

            ans.push_back({ ++swapped, i+1 });

            if (i >= o) {
                ones_pos.insert(i);
            }
        }

        for (int i = z; i < o; ++i) {
            if (a[i] != 2) continue;

            ans.push_back({ *ones_pos.begin()+1, i+1 });
            ones_pos.erase(*ones_pos.begin());
        }

        cout << ans.size() << '\n';
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    return 0;
}
