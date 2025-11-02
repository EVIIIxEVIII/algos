#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long r0, x, d, n;
        cin >> r0 >> x >> d >> n;

        string s;
        cin >> s;

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '2' && r0 < x) {
                ans++;
            } else if (s[i] == '1') {
                ans++;
                r0 = max(0LL, r0 - d);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
