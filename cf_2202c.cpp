#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = n;
        for (int i = 0; i < n;) {
            int s = a[i];
            int e = a[i];

            int j = i + 1;
            while (j < n) {
                if (a[j] >= s + 1 && a[j] <= e + 1) {
                    e = a[j];
                } else {
                    break;
                }
                j++;
            }

            ans -= (j - 1 - i);
            i = j;
        }

        cout << ans << '\n';
    }
    return 0;
}
