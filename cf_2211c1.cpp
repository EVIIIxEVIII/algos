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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n - k; ++i) {
        if (b[i] != -1 && b[i] != a[i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = k; i < n; ++i) {
        if (b[i] != -1 && b[i] != a[i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    set<int> set_a;
    set<int> set_b;

    for (int i = n - k; i < k; ++i) {
        set_a.insert(a[i]);
    }

    for (int i = n - k; i < k; ++i) {
        if (b[i] != -1) {
            if (!set_a.contains(b[i]) || !set_b.insert(b[i]).second) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}
