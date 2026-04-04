#include <bits/stdc++.h>
using namespace std;

void solve1();
void solve2();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int g = t;

    //while (g--) solve1();
    while (t--) solve2();

    return 0;
}

void solve1() {
    int n; cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + a[i-1];
    }

    auto f = [&](long long x) -> long long {
        return x*x + x - pref[x];
    };

    long long min_val = 0;
    long long ans = pref[n];

    for (int r = 1; r <= n; ++r) {
        ans = max(ans, pref[n] + f(r) - min_val);
        min_val = min(f(r), min_val);
    }

    cout << ans << '\n';
}

void solve2() {
    int n; cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i] = max(a[i], dp[i-1] + a[i]);
    //

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = 2*(i+1) - a[i];
    }

    long long curr = 0;
    long long ans = 0;

    int cur_l = 0;
    int best_l = -1;
    int best_r = -1;

    for (int i = 0; i < n; ++i) {
        if (b[i] > curr + b[i]) {
            cur_l = i;
            curr = b[i];
        } else {
            curr += b[i];
        }

        if (curr > ans) {
            ans = curr;
            best_l = cur_l;
            best_r = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }

    cout << ans << '\n';
}
