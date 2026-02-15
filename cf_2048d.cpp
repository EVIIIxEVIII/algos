#include <algorithm>
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
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        int r = a[0];

        // idea: we could firstly try to pick all the problems b[i] <= r, and then go from harders
        // to easiest when we run out of them.
        // idea: for each k, we could find the number of problems such that b[i] <= r, note that that number as p
        // and have floor(p/k) contests where Kev is at rank 1. Then we could go from the other side and check the remaining
        // floor(m/k) - floor(p/k) problems from highest rated to lowest rated and take into account the remaining p % k low
        // rated problems somehow.
        // But this would require to answer the question: how many contests have rating >= b[i].

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        //a.erase(a.begin(), lower_bound(a.begin(), a.end(), r));

        vector<int> cnt(m, 0);
        for (int i = 0; i < m; ++i) {
            if (b[i] > r) {
                cnt[i] = a.end() - std::lower_bound(a.begin(), a.end(), b[i]);
            }
        }

        sort(cnt.begin(), cnt.end());

        for (int k = 1; k <= m; ++k) {
            long long ans = 0;
            for (int i = k - 1; i < m; i += k) {
                ans += cnt[i] + 1;
            }
            cout << ans << ' ';
        }

        cout << '\n';
    }
    return 0;
}
