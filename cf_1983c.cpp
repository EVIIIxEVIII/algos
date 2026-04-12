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
    int n; cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);

    long long tot = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; tot += a[i]; }
    for (int i = 0; i < n; ++i) { cin >> b[i]; }
    for (int i = 0; i < n; ++i) { cin >> c[i]; }

    long long need = (tot + 2) / 3;

    vector<long long> a_pref(n+1);
    vector<long long> b_pref(n+1);
    vector<long long> c_pref(n+1);

    a_pref[0] = 0;
    b_pref[0] = 0;
    c_pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a_pref[i] = a_pref[i-1] + a[i-1];
        b_pref[i] = b_pref[i-1] + b[i-1];
        c_pref[i] = c_pref[i-1] + c[i-1];
    }

    auto check = [&](auto& a, auto& b, auto& c) -> array<int,6> {
        int r = 2;
        for (int l = 1; l < n; ++l) {
            while (r < n && a[r] - a[l] < need) {
                r++;
            }
            if (b[l] - b[0] >= need && c[n] - c[r] >= need) {
                return {l+1,r,1,l,r+1,n};
            }
            if (c[l] - c[0] >= need && b[n] - b[r] >= need) {
                return {l+1,r,r+1,n,1,l};
            }
        }
        return {-1, -1, -1, -1, -1, -1};
    };

    auto ans1 = check(a_pref, b_pref, c_pref);
    auto ans2 = check(b_pref, a_pref, c_pref);
    auto ans3 = check(c_pref, a_pref, b_pref);

    if (ans1[0] != -1) {
        auto [la,ra,lb,rb,lc,rc] = ans1;
        cout << la<< ' ' << ra<< ' ' << lb<< ' ' << rb<< ' ' << lc<< ' ' << rc << '\n';
        return;
    } else if (ans2[0] != -1) {
        auto [lb,rb,la,ra,lc,rc] = ans2;
        cout << la<< ' ' << ra<< ' ' << lb<< ' ' << rb<< ' ' << lc<< ' ' << rc << '\n';
    } else if (ans3[0] != -1) {
        auto [lc,rc,la,ra,lb,rb] = ans3;
        cout << la<< ' ' << ra<< ' ' << lb<< ' ' << rb<< ' ' << lc<< ' ' << rc << '\n';
    } else {
        cout << -1 << '\n';
    }
}
