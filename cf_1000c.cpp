#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<set<int>> map(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;

            map[u].insert(v);
            map[v].insert(u);
        }

        vector<int> scores(n+1);
        for (int i = 1; i <= n; ++i) {
            scores[i] = map[i].size() - 1;
        }

        int max1 = 1;
        for (int i = 2; i <= n; ++i) {
            if (scores[i] > scores[max1]) max1 = i;
        }

        int max2 = (max1 == 1 ? 2 : 1);
        for (int i = 1; i <= n; ++i) {
            if (i != max1 && scores[i] > scores[max2]) max2 = i;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == max1) continue;
            bool adj = map[max1].find(i) != map[max1].end();
            ans = max(ans, 1 + scores[max1] + scores[i] - (adj ? 1 : 0));
        }

        for (int i = 1; i <= n; ++i) {
            if (i == max2) continue;
            bool adj = map[max2].find(i) != map[max2].end();
            ans = max(ans, 1 + scores[max2] + scores[i] - (adj ? 1 : 0));
        }

        cout << ans << '\n';
    }
    return 0;
}
