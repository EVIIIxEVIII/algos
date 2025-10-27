#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        string s;
        cin >> s;

        vector<int> a(q);
        for (int i = 0; i < q; ++i) {
            cin >> a[i];
        }

        bool bPresent = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                bPresent = true;
                break;
            }
        }

        if (!bPresent) {
            for (int i = 0; i < q; ++i) {
                cout << a[i] << '\n';
            }
            continue;
        }

        for (int i = 0; i < q; ++i) {
            int val = a[i];

            int ans = 0;
            int j = 0;
            while (val) {
                if (s[j] == 'A') {
                    val--;
                } else {
                    val /= 2;
                }
                j = (j+1)%n;
                ans++;
            }

            cout << ans << '\n';
        }
    }
    return 0;
}
