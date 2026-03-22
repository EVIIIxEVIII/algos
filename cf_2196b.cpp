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
    long long n; cin >> n;

    vector<long long> a(n);
    vector<pair<long long, int>> f;
    vector<pair<long long, int>> s;

    for (int i = 0; i < n; ++i) {
        long long val; cin >> val;

        a[i] = val;

        if (val * val < n) {
            f.push_back({ val, i });
        } else {
            s.push_back({ val, i });
        }
    }

    long long ans = 0;
    for (auto& [ai, i] : f) {
        for (long long k = 1; k * k < n; ++k) {
            long long idx = ai * k + i;

            if (idx >= n) {
                break;
            }

            if (a[idx] == k) {
                ans++;
            }
        }
    }

    for (auto& [ai, i] : s) {

        for (long long k = 1; k * k < n; ++k) {
            long long idx = i - ai * k;
            if (idx < 0) break;
            if ((i - idx) == (a[idx] * ai)) {
                ans++;
            }
        }

        for (long long k = 1; k * k < n; ++k) {
            long long idx = ai * k + i;
            if (idx >= n) break;

            if ((idx - i) == (a[idx] * ai)) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
