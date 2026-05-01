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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            g[i][j] = c-'0';
        }
    }

    auto strip = [&](int s, vector<int>& target) {
        int top = s;
        int bottom = n - 1 - s;
        int left = s;
        int right = m - 1 - s;

        for (int i = left; i <= right; ++i) {
            target.push_back(g[top][i]);
        }

        for (int i = top+1; i <= bottom; ++i) {
            target.push_back(g[i][right]);
        }

        for (int i = right - 1; i >= left; --i) {
            target.push_back(g[bottom][i]);
        }

        for (int i = bottom - 1; i > top; --i) {
            target.push_back(g[i][left]);
        }
    };

    vector<vector<int>> vals;
    for (int i = 0; i < min(n/2, m/2); ++i) {
        vector<int> s;
        strip(i, s);
        vals.push_back(s);
    };

    for (auto& val : vals) {
        val.push_back(val[0]);
        val.push_back(val[1]);
        val.push_back(val[2]);
        val.push_back(val[3]);
    }

    long long ans = 0;
    for (auto& val : vals) {
        for (int i = 0; i < (int)val.size()-4; ++i) {
            if (val[i] * 1000 + val[i+1] * 100 + val[i+2]*10 + val[i+3] == 1543) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
