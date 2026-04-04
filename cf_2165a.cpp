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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> l(n);
    vector<int> r(n);

    for (int i = 0; i < n; ++i) {
        int left = i == 0 ? n - 1 : i - 1;
        int right = i == n - 1 ? 0 : i + 1;

        l[i] = left;
        r[i] = right;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    long long ans = 0;
    for (int j = 0; j < n - 1; j++) {
        int i = idx[j];
        ans += min(a[l[i]], a[r[i]]);

        r[l[i]] = r[i];
        l[r[i]] = l[i];
    }

    cout << ans << '\n';
}
