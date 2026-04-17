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
    long long k; cin >> k;

    int lines = 0;
    vector<pair<int,int>> ans;
    auto construct_line = [&](long long k) {
        long long line_sz = (1 + sqrtl(1 + 8.0L * k)) / 2;
        long long rem = k - (line_sz * (line_sz - 1))/2;

        for (int i = 0; i < line_sz; ++i) {
            ans.push_back({ ans.size(), lines });
        }

        lines++;
        return rem;
    };

    while (k > 0) {
        k = construct_line(k);
    }

    cout << ans.size() << '\n';
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}
