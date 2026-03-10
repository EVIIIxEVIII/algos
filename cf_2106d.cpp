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

    vector<int> p(m);
    vector<int> s(m);

    int l = 0;
    for (int i = 0; i < m; ++i) {
        while (l < n && b[i] > a[l]) l++;
        if (l == n) {
            p[i] = n;
        } else {
            p[i] = l;
            l++;
        }
    }

    int r = n - 1;
    for (int i = m - 1; i >= 0; --i) {
        while (r >= 0 && b[i] > a[r]) r--;
        if (r < 0) {
            s[i] = -1;
        } else {
            s[i] = r;
            r--;
        }
    }

    if (p[m-1] != n) {
        cout << 0 << '\n';
        return;
    }

    if (s[0] != -1) {
        cout << 0 << '\n';
        return;
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; ++i) {
        int l = (i == 0) ? -1 : p[i-1];
        int r = (i == m-1) ? n : s[i+1];

        if (l < r) {
            ans = min(ans, b[i]);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
