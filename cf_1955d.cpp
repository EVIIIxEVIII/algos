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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    unordered_map<int, int> cnt_win;
    unordered_map<int, int> cnt_target;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        cnt_target[b[i]]++;
    }

    long long matches = 0;
    for (int i = 0; i < m; ++i) {
        if (cnt_win[a[i]] < cnt_target[a[i]]) {
            matches++;
        }
        cnt_win[a[i]]++;
    }

    long long ans = matches >= k;

    int l = 0, r = m;
    while (r < n) {
        if (cnt_win[a[l]] - 1 < cnt_target[a[l]]) {
            matches--;
        }
        cnt_win[a[l]]--;

        if (cnt_win[a[r]] < cnt_target[a[r]]) {
            matches++;
        }
        cnt_win[a[r]]++;

        if (matches >= k) {
            ans++;
        }

        l++;
        r++;
    }

    cout << ans << '\n';
}
