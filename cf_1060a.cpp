#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;

        string s;
        cin >> s;

        int prevOne = -1;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') continue;
            if (prevOne == -1) {
                prevOne = i;
                ans++;
                continue;
            }

            if (i - prevOne > k-1) {
                ans++;
            }

            prevOne = i;
        }

        cout << ans << '\n';
    }
    return 0;
}
