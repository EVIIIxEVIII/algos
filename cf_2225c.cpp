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

    vector<vector<char>> g(2, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        cin >> g[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> g[1][i];
    }


    long long ans = 0;
    for (int i = 0; i < n;) {
        int v = g[0][i] != g[1][i];
        if (i + 1 >= n) {
            ans += v;
            break;
        }
        int h = (g[0][i+1] != g[0][i]) + (g[1][i+1] != g[1][i]);

        if (v < h) {
            ans += v;
            i++;
        } else {
            ans += h;
            i += 2;
        }
    }

    cout << ans << '\n';
}
