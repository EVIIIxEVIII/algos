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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    cout << (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2 ? "YES" : "NO") << '\n';
}
