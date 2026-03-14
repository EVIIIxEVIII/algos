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
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the k - 1 minimum cards will be played

    int ans = 0;

    vector<int> l;
    for (int i = 0; i < p; ++i) {
        l.push_back(a[i]);
    }

    sort(l.begin(), l.end());

    int init = a[p];
    for (int i = 0; i < p - k + 1; ++i) {
        init += l[i];
    }

    if (init <= m) {
        ans++;
        m -= init;
    } else {
        cout << 0 << '\n';
        return;
    }

    int cycle = a[p];
    a.erase(a.begin() + p);
    sort(a.begin(), a.end());

    for (int i = 0; i < n - k; ++i) {
        cycle += a[i];
    }

    ans += m / cycle;

    cout << ans << '\n';
}
