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
    int n; cin >> n;

    vector<int> c(n);
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        cin >> p[i];
    }

    double answer = c[n-1];
    for (int i = n - 2; i >= 0; --i) {
        answer = max(answer, c[i] + (1.0 - p[i]/100.0) * answer);
    }

    cout << std::fixed << std::setprecision(10) << answer << '\n';
}
