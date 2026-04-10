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
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; ++i) {
        long long best = LLONG_MAX;
        if (a[i] >= a[i-1]) {
            best = a[i];
        }

        long long need = a[i-1] + a[i];
        auto it = lower_bound(b.begin(), b.end(), need);
        if (it != b.end()) {
            long long cand = *it - a[i];
            if (cand >= a[i-1]) {
                best = min(best, cand);
            }
        }

        if (best == LLONG_MAX) {
            cout << "NO" << '\n';
            return;
        }

        a[i] = best;
    }

    cout << "YES" << '\n';
}
