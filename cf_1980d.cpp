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

    auto check = [&](int j) {
        for (int i = 1; i < n-1; ++i) {
            int prev = i-1 == j ? i-2 : i-1;
            int curr = i == j ? i+1 : i;
            int next = i+1 == j ? i+2 : i+1;
            if (prev < 0 || next >= n) continue;

            if (gcd(a[prev], a[curr]) > gcd(a[curr], a[next])) {
                return false;
            }
        }
        return true;
    };

    for (int i = 1; i < n-1; ++i) {
        if (gcd(a[i-1], a[i]) > gcd(a[i], a[i+1])) {
            if (check(i-1) || check(i) || check(i+1)) {
                cout << "YES" << '\n';
                return;
            } else {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}
