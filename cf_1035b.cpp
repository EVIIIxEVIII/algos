#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        long long px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<double> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        double target = sqrt((qx - px)*(qx - px) + (qy - py)*(qy - py));

        if (n == 1) {
            cout << (a[0] == target ? "YES" : "NO") << '\n';
            continue;
        }

        a.push_back(target);

        double maxVal = 0;
        for (int i = 0; i <= n; ++i) {
            maxVal = max(maxVal, a[i]);
        }

        double sum = 0;
        for (int i = 0; i <= n; ++i) sum += a[i];

        if ((sum - maxVal) >= maxVal) cout << "YES" << '\n';
        else cout << "NO" << '\n';
   }

    return 0;
}
