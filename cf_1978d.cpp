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
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    a[0] += c;

    // prefix sums?
    int max_val = 0;
    int max_val_i = 0;
    for (int i = 0; i < n; ++i) {
        if (max_val< a[i]) {
            max_val = a[i];
            max_val_i = i;
        }
    }

    vector<long long> pref(n);
    pref[0] = a[0];

    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i-1] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == max_val_i) {
            cout << 0 << ' ';
            continue;
        }

        if (pref[i] >= max_val) {
            cout << i << ' ';
        } else {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}
