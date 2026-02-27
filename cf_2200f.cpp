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

    vector<tuple<long long, int, int>> dp(n+2, {0, 0, 0});
    vector<long long> used;

    long long ans = 0;
    for (int i = n; i >= 0; --i) {
        for (auto x : part_map[i]) {
            used.push_back(x);
        }

        sort(used.begin(), used.end(), greater<long long>());

        long long min_en = LLONG_MAX;
        int used_part = min(used.size(), size_t(i));
        long long sum = 0;

        if (used_part != 0) {
            min_en = used[0];
        }

        for (int j = 0; j < used_part; ++j) {
            sum += used[j];
            min_en = min(min_en, used[j]);
        }

        ans = max(ans, sum);
        dp[i] = { min_en, sum, used_part };
    }

    for (int i = 1; i <= m; ++i) {
        auto [ x, y ] = s[i];
        auto [ min_en, sum, used_part ] = dp[y];

        long long local_ans = ans;
        if (used_part <= y + 1) {
            local_ans = max(local_ans, 1LL * sum + x);
        } else {
            local_ans = max(local_ans, (sum - min_en) + x);
        }

        cout << local_ans << ' ';
    }

    cout << '\n';
}
