#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        cin >> p[i].second;
    }

    vector<pair<int, int>> s(m+1);
    for (int i = 1; i <= m; ++i) {
        cin >> s[i].first;
        cin >> s[i].second;
    }

    // precompute the best energy for all number of particles, find the maximum one, and also keep
    // the minimum energy of a particle for all number of particles.
    // so dp[i] = {min_energy_part_used, sum} where i is the number of used particles

    vector<vector<long long>> part_map(n+1);
    for (int i = 0; i < n; ++i) {
        part_map[p[i].second].push_back(p[i].first);
    }

    multiset<long long> used;
    long long used_pref = 0;
    vector<long long> pref(n+1);

    long long ans = 0;
    for (int i = n; i >= 0; --i) {
        while (used.size() > i + 1) {
            used_pref -= *used.begin();
            used.erase(used.begin());
        }

        for (auto x : part_map[i]) {
            if (used.size() < i + 1) {
                used.insert(x);
                used_pref += x;
            } else if (*used.begin() < x) {
                used_pref -= *used.begin();
                used.erase(used.begin());
                used.insert(x);
                used_pref += x;
            }
        }

        ans = max(ans, used_pref);
        if (used.size() <= i) {
            pref[i] = used_pref;
        } else {
            pref[i] = used_pref - *used.begin();
        }
    }

    for (int i = 1; i <= n; ++i) {
        pref[i] = max(pref[i-1], pref[i]);
    }

    for (int i = 1; i <= m; ++i) {
        auto [ x, y ] = s[i];
        auto best_en_at_y = pref[y];

        long long local_ans = max(ans, best_en_at_y + x);
        cout << local_ans << ' ';
    }

    cout << '\n';
}
