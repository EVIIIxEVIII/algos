#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, vector<int>> person_locs;

        vector<vector<int>> blogs(n);
        for (int i = 0; i < n; ++i) {
            int l_i;
            cin >> l_i;

            blogs[i].resize(l_i);
            unordered_set<int> seen;

            for (int j = l_i - 1; j >= 0; --j) {
                cin >> blogs[i][j];

                if (!seen.contains(blogs[i][j])) {
                    seen.insert(blogs[i][j]);
                    person_locs[blogs[i][j]].push_back(i);
                }
            }
        }

        vector<int> ans;
        unordered_set<int> seen;

        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
