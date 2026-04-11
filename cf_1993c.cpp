#include <algorithm>
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
    long long n, k; cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> a_mod(n);
    for (int i = 0; i < n; ++i) {
        a_mod[i] = a[i] % (2*k);
    }

    sort(a_mod.begin(), a_mod.end());
    vector<long long> ext = a_mod;

    for (int i = 0; i < n; ++i) {
        ext.push_back(a_mod[i] + 2*k);
    }

    long long maximum = *max_element(a.begin(), a.end());
    long long ans = -1;

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (ext[n + i - 1] - ext[i] < k) {
            ok = true;

            long long L = ext[n + i - 1];
            long long R = ext[i] + k - 1;
            long long mod = 2*k;

            long long q = 0;
            if (maximum > R) {
                q = (maximum - R + mod - 1) / mod;
            }

            ans = max(maximum, L + q*mod);
            break;
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    cout << ans << '\n';
}
