#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        vector<bool> visited(n+1, false);
        auto dfs = [&](auto&& self, int i, int count=1) {
            if (visited[i]) {
                return --count;
            }

            visited[i] = true;
            return self(self, p[i], ++count);
        };


        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            int cycle = dfs(dfs, p[i]);

            if (cycle >= 3) {
                ans += (cycle - 4 + cycle%2) / 2 + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
