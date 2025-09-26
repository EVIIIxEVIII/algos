#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> ans(n, 0);
        int useTwo = (n % 2 || (x - y) % 2 == 0);

        x--; y--;
        for (int i = 0; i < n; ++i) {
            int idx = ((x) + i) % n;

            if (idx == x) {
                ans[idx] = (useTwo ? 2 : i % 2);
            } else {
                ans[idx] = i % 2;
            }
        }

        for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
