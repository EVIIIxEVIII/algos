#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        set<int> a_set;
        for (int i = 0; i < n; ++i) {
            a_set.insert(a[i]);
        }

        int common = 0;
        for (int i = 0; i < m; ++i) {
            if (a_set.count(b[i])) {
                common++;
            }
        }

        int ans = 0;
        if (n - common > m - common) {
            ans++;
        }

        ans += 2*min(n - common, m - common) + 1;
        cout << ans << '\n';
    }
    return 0;
}
