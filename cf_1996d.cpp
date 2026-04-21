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
    int n, x;
    cin >> n >> x;

    // maybe find the first pair of same numbers (x, x, x) such that x*x + x*x + x*x <= n ans 3*x <= x, then
    // the number of pairs will be x^3.
    // then after that we could try to increase one x to x + 1, and get (x + 1)*x + (x+1)*x + x*x and if <= n and the second
    // condition hold we can add x*x, otherwise we decrease one element by one and try again, but we should account of the swap
    // between those positions so we would do x*(x - 1)*2 etc.


    long long ans = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n/a; ++b) {
            int c_range = min((n - a*b)/(a + b), x - b - a);
            if (c_range >= 1) {
                ans += c_range;
            }
        }
    }

    cout << ans << '\n';
}
