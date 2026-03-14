#include <bits/stdc++.h>
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

    double initial = 0;

    vector<double> per(n);

    double S = 1;
    for (int i = 0; i < n; ++i) {
        per[i] = S * c[i];
        S = S * (1 - (p[i]) / 100);

        initial += per[i];
    }

    vector<double> s(n);
    s[n-1] = 0;

    for (int i = n - 2; i >= 0; --i) {
        s[i] = s[i + 1] + per[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        double rem_gain = s[i] / (1 - p[i] / 100);

        if (rem_gain > c[i]) {
            initial -= per[i];
            initial += rem_gain;
        }
    }

    cout << initial << '\n';
}
