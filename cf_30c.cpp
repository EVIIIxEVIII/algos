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

        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        int maxSword = 0;
        int maxPotentialSword = 0;

        for (int i = 0; i < n; ++i) {
            maxSword = max(maxSword, a[i]);
            maxPotentialSword = max(maxPotentialSword, c[i]);
        }

        vector<int> idx(c.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return c[i] < c[j];
        });

        vector<int> c_sorted;
        vector<int> b_sorted;

        for (int i : idx) {
            c_sorted.push_back(c[i]);
            b_sorted.push_back(b[i]);
        }

        for (int i = 0; i < m; ++i) {
            cout << b_sorted[i] << ' ';
        }
        cout << '\n';

        for (int i = 0; i < m; ++i) {
            cout << c_sorted[i] << ' ';
        }
        cout << '\n';


    }

    return 0;
}
