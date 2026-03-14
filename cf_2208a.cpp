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

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    vector<int> cnt(n*n + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            cnt[g[i][j]]++;

        }
    }

    sort(cnt.begin(), cnt.end(), std::greater<int>());

    if (cnt[0] <= (n * n - n)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
