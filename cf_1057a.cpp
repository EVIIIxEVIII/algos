#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < a.size(); ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int ans = 0;
        int last = -1;

        for (int i = 0; i < a.size(); ++i) {
            if (last < a[i]) {
                ans++;
                last = a[i];
            }
        }

        cout << ans << '\n';

    }
    return 0;
}
