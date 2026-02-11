#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        // idea: max(x - y, y - x) => for all substrings there
        // should be no more than k repeating values
        //
        // idea: for all substrings with x repeating values of 1s
        // the next substring must have x repeating values of 0s
        // and x <= k.
        //
        // idea: k 0s, k 1s, 0, 1, 0...?
        //
        // k max(0s, 1s), min(0s, 1s)...?
        //
        // abs(max(n, m) - k - min(n, m)) <= k
        //
        // n = 9
        // m = 2
        // k = 4
        //
        // 9 - 4 - 2
        //
        // 00001010000
        //
        // 16 11 23

        if (max(n - m, m - n) > k || max(n, m) < k) {
            cout << -1 << '\n';
            continue;
        }

        string ans;

        int first = 1;
        int second = 0;

        int fcnt = m;
        int scnt = n;

        if (n > m) {
            swap(first, second);
            swap(fcnt, scnt);
        }

        fcnt -= k;
        for (int i = 0; i < k; ++i) {
            ans.push_back(first + '0');
        }

        int i = 1;
        while (fcnt > 0 && scnt > 0) {
            if (i & 1) {
                ans.push_back(second + '0');
                scnt--;
            } else {
                ans.push_back(first + '0');
                fcnt--;
            }
            ++i;
        }

        if (fcnt > 0) {
            for (int i = 0; i < fcnt; ++i)
                ans.push_back(first + '0');
        }

        if (scnt > 0) {
            for (int i = 0; i < scnt; ++i)
                ans.push_back(second + '0');
        }

        cout << ans << '\n';
    }

    return 0;
}
