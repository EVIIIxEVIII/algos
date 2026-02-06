#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        int ans = 0;

        if (cd > ck) {
            ans = max(ans, cd);
        } else if (cd < ck) {
            ans = max(ans, n - cd);
        }

        if (rd > rk) {
            ans = max(ans, rd);
        } else if (rd < rk) {
            ans = max(ans, n - rd);
        }

        cout << ans << '\n';
    }
    return 0;
}
