#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;

        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int startingVal = a[k];
        sort(a.begin(), a.end());

        int startingValIdx = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == startingVal) {
                startingValIdx = i;
            }
        }

        bool ans = true;
        int waterLevel = 1;
        for (int i = startingValIdx; i <= n;) {
            int current = a[i];

            while (i+1 <= n && a[i] == current) {
                i++;
            }

            if (current == a[i]) break;

            if (current < waterLevel + (a[i] - current - 1)) {
                ans = false;
                break;
            } else {
                waterLevel += (a[i] - current);
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
