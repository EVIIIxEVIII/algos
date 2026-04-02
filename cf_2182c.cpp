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
    vector<int> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    auto check = [&](int offset, vector<int>& arr, auto&& cmp) -> bool {
        for (int i = 0; i < n; ++i) {
            if (!cmp(arr[(i+offset)%n], b[i])) {
                return false;
            }
        }

        return true;
    };

    long long ans = 0;
    int is = 0;
    int ks = 0;

    for (int offset = 0; offset < n; ++offset) {
        if (check(offset, a, less<int>())) {
            is++;
        }
    }

    for (int offset = 0; offset < n; ++offset) {
        if (check(offset, c, greater<int>())) {
            ks++;
        }
    }

    cout << 1LL * n * is * ks << '\n';
}
