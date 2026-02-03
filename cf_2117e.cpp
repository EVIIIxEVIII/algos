#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // idea: find the best possible pair of identical numbers besides numbers where a[i] == b[i+1] or vice versa,
        // those aren't valid, however pairs where a[i] == a[i+1] or b[i] == b[i+1] are valid. The best pair would be
        // considered a pair where the min(i, j) would be maximized
        //
        // idea: go from end to start and ask for each a[i] and b[i]: "what is the closest number a[i] in both a and b?"

        unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            map[a[i]] = i;
            map[b[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (map[b[i]] > i && map[b[i]] != i+1) {
                ans = max(i+1,  ans);
            }

            if (map[a[i]] > i && map[a[i]] != i+1) {
                ans = max(i+1,  ans);
            }

            if (map[a[i]] == i && a[i] == b[i]) {
                ans = max(i+1, ans);
            }

            if (map[b[i]] == i && a[i] == b[i]) {
                ans = max(i+1, ans);
            }

            if (map[a[i]] == i+1 && a[i] == a[i+1]) {
                ans = max(i+1, ans);
            }

            if (map[b[i]] == i+1 && b[i] == b[i+1]) {
                ans = max(i+1, ans);
            }

        }

        cout << ans << '\n';

    }
    return 0;
}
