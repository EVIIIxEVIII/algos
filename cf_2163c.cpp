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
    long long n;
    cin >> n;

    vector<vector<long long>> a(2, vector<long long>(n));
    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long inf = 1e18;

    vector<vector<pair<long long, long long>>> pos(2*n + 1);
    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < n; ++j) {
            pos[a[i][j]].push_back({i, j});
        }
    }

    array<set<long long>, 2> dis;
    dis[0].insert(inf);
    dis[1].insert(-inf);

    for (long long i = 0; i < n; ++i) {
        dis[0].insert(i);
        dis[1].insert(i);
    }

    auto add = [&](long long x) {
        for (auto [i, j] : pos[x]) {
            dis[i].erase(j);
        }
    };

    auto remove = [&](long long x) {
        for (auto [i, j] : pos[x]) {
            dis[i].insert(j);
        }
    };

    auto check = [&]() {
        if (dis[0].contains(0)) return false;
        if (dis[1].contains(n-1)) return false;
        if (*dis[0].begin() - 1 <= *dis[1].rbegin()) return false;

        return true;
    };

    long long r = 0;
    long long ans = 0;

    for (long long l = 1; l <= 2*n; ++l) {
        while (r < 2*n && !check()) {
            r++;
            add(r);
        }

        if (!check()) break;

        ans += 2*n - r + 1;
        remove(l);
    }

    cout << ans << '\n';
}
