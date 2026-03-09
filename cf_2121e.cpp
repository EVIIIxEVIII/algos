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
    long long l, r;
    cin >> l >> r;

    int num = l;
    int n = 0;
    int exp = 1;

    while (num > 0) {
        num /= 10;
        exp *= 10;
        n++;
    }
    exp/=10;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int dl = (l / exp) % 10;
        int dr = (r / exp) % 10;

        if (dl == dr) {
            ans += 2;
        } else if (abs(dl - dr) == 1) {
            ans++;
        } else break;

        exp /= 10;
    }

    cout << ans << '\n';
}
