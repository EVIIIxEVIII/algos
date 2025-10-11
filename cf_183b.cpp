#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        s.resize(k);
        for (int i = 0; i < k; ++i) {
            cin >> s[i];
        }

        int qs = 0;
        int top = 0;
        int bottom = 0;

        for (int i = 0; i < k; ++i) {
            if (s[i] == '0') {
                top++;
            } else if (s[i] == '1') {
                bottom++;
            } else if (s[i] == '2') {
                qs++;
            }
        }

        string ans(n, '+');
        for (int i = 0; i < n; ++i) {
            if (i < top + qs || i >= n - bottom - qs) { ans[i] = '?'; }
            if (i < top || i >= n - bottom || k==n) { ans[i] = '-'; }
        }

        cout << ans << '\n';
    }
    return 0;
}
