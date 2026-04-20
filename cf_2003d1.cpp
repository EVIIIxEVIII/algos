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
    long long n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        for (int j = 0; j < l; ++j) {
            int a_l_j; cin >> a_l_j;
            a[i].push_back(a_l_j);
        }
    }

    // might be constnat per m, i.e m*c. however, it might be better to live x as is, so max(x, m*c)
    // each sequence contributes at most 2 values: 1 value when it has no "gaps" and 2 values when it has exactly
    // one "gap" where a gap is defined as a point a[i], a[i+1] such that a[i] + 2 == a[i+1].
    // More generally each sequence contributes 1 past its original mex.
    auto second_mex = [&](vector<int>& v) {
        sort(v.begin(), v.end());
        long long need = 0;
        long long missing = 0;
        for (int j = 0; j < (int)v.size(); ++j) {
            if (v[j] < need) continue;
            while (need < v[j]) {
                missing++;
                if (missing == 2) return need;
                need++;
            }
            need++;
        }

        if (missing == 0) return need + 1;
        return need;
    };

    long long max_mex = 0;
    for (int i = 0; i < n; ++i) {
        max_mex = max(max_mex, second_mex(a[i]));
    }

    long long ans = max_mex * (min(max_mex - 1, m) + 1) + ((m + max_mex) * max(0LL, (m - max_mex + 1)) / 2);
    cout << ans << '\n';
}
