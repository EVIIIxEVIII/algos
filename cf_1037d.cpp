#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> l(n);
        vector<int> r(n);
        vector<int> real(n);

        // important thing: real is always between l and r, so there is no need for dp here

        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            cin >> r[i];
            cin >> real[i];
        }

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return l[i] < l[j];
        });


        vector<int> l_sorted(n);
        vector<int> r_sorted(n);
        vector<int> real_sorted(n);

        for (int i = 0; i < n; ++i) {
            int idx = indices[i];
            l_sorted[i] = l[idx];
            r_sorted[i] = r[idx];
            real_sorted[i] = real[idx];
        }

        int ans = k;
        for (int i = 0; i < n; ++i) {
            if (l_sorted[i] <= ans) {
                ans = max(ans, real_sorted[i]);
            } else break;
        }

        cout << ans << '\n';
    }

    return 0;
}
