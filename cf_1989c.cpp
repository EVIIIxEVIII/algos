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

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int a_cnt = 0;
    int b_cnt = 0;

    int add = 0;
    int rem = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            a_cnt += a[i];
        } else if (b[i] > a[i]) {
            b_cnt += b[i];
        } else if (a[i] < 0) {
            rem++;
        } else if (a[i] > 0) {
            add++;
        }
    }

    int ans = INT_MIN;
    for (int i = -rem; i <= add; ++i) {
        ans = max(ans, min(a_cnt + i, b_cnt + (add - rem - i)));
    }

    cout << ans << '\n';
}
