#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        int m; cin >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());

        long long total = accumulate(a.begin(), a.end(), 0LL);

        int i = 0;
        for (int j = 0; j < m; ++j) {
            int r = i + b[j] - 1;
            if (r >= n) break;
            total -= (long long)a[r];
            i += b[j];
        }

        cout << total << '\n';

        //long long total = accumulate(a.begin(), a.end(), 0LL);
        //long long saved = 0;
        //int pref = 0;

        //for (int x : b) {
        //    if (pref + x > n) break;
        //    saved += a[pref + x - 1];
        //    pref += x;
        //}

        //cout << (total - saved) << '\n';
   }

    return 0;
}
