#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool ans = false;
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                zeros += 1;
                int prev = i-1 >= 0 ? a[i-1] : 1;
                int next = i+1 < n ? a[i+1] : 1;

                if (!prev || !next) {
                    ans = true;
                    break;
                }
            }
        }

        cout << ((ans || !zeros) ? "YES" : "NO") << '\n';
    }
    return 0;
}
