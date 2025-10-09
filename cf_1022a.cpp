#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;


        int ans = 0;
        if (n % 2 == 0) {
            for (int i = 0; i < n/2; ++i) {
               ans += (i*2+1);
            }
        } else {
            for (int i = 1; i <= n/2; ++i) {
               ans += (i*2);
            }
        }

        cout << ans + 1 << '\n';

    }
    return 0;
}
