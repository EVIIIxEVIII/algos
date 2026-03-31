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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i< n; ++i) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    int min_el = b.front();
    int max_el = b.back();

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ans = min(ans, max(a[i] - min_el, max_el - a[i]));
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
