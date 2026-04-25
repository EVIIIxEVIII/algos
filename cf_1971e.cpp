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
    int n, k, q;
    cin >> n >> k >> q;

    vector<long long> a(k+1);
    vector<long long> b(k+1);

    a[0] = 0;
    b[0] = 0;

    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i) {
        int d;
        cin >> d;

        int j = lower_bound(a.begin(), a.end(), d) - a.begin();

        if (d == a[j]) {
            cout << b[j] << ' ';
            continue;
        }

        long long dist = a[j] - a[j-1];
        long long time = b[j] - b[j-1];
        long long dst = d - a[j-1];

        cout << (b[j-1] * dist + dst * time) / dist << ' ';
    }
    cout << '\n';
}
