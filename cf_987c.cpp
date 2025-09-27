#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n%2 && n < 27) {
            cout << -1 << '\n';
            continue;
        }

        int curr = 0;
        vector<int> a(n);

        if (n%2 == 0) {
            for (int i = 0; i < n; ++i) {
                if (i%2 == 0) curr++;
                a[i] = curr;
            }
        } else {
            a[0] = 1;
            a[9] = 1;
            a[10] = 2;
            a[25] = 1;
            a[26] = 2;

            curr = 3;
            int times = 0;

            for (int i = 1; i < n; ++i) {
                if (a[i] != 0) continue;

                if (times >= 2) {
                    times = 0;
                    curr++;
                }

                a[i] = curr;
                times++;
            }
        }

        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
