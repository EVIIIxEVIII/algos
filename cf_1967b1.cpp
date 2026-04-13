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
    int n, m; cin >> n >> m;

    // b*gcd(a,b) | (a + b) => y*g^2 | (x*g + y*g) => y*g | (x + y)
    // we have y | (x + y) => y | (x + y - y) => y | x, because gcd(x, y) = 1,
    // we have y = 1. Now let x + y = y*g*k, x = (gk - 1)*y, since y = 1 we have
    // x = (gk - 1). We have a = g*x => x <= floor(n/g).
    // We can try all g from 1 to m, where x + 1 = gk and x + 1 = gk <= floor(n/g) + 1
    // so 1 <= k <= floor((floor(n/g)+1) / g).
    //

    long long ans = 0;
    for (int g = 1; g <= m; ++g) {
        ans += ((n / g) + 1) / g;
    }
    cout << ans - 1 << '\n';
}
