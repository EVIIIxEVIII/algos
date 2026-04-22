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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k+1);
    vector<int> b(k+1);

    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i) {
        int d; cin >> d;

        auto it = lower_bound(a.begin(), a.end(), d);
        int j = it - a.begin();
        if (d == a[j]) {
            cout << b[j] << ' ';
            continue;
        }

        // the take away: in int arithmetic division must be placed last otherwise it won't work correctly
        cout << 1LL * b[j-1] + 1LL * (d - a[j-1])  * (b[j] - b[j-1]) / (a[j] - a[j-1]) << ' ';
    }

    cout << '\n';
}
