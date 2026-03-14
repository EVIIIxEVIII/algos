#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<double> c(n);
    vector<double> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> p[i];
    }

    double ans = c[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ans = max(ans, c[i] + ans * (1.0 - p[i] / 100.0));
    }

    cout << fixed << setprecision(10) << ans << '\n';
}
