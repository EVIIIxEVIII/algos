#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int maxPos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[maxPos] < a[i]) {
                maxPos = i;
            }
        }

        int num = a[maxPos];
        int l = maxPos == 0 ? maxPos : maxPos-1;
        int r = maxPos == n - 1 ? maxPos : maxPos+1;

        bool ans = true;
        while (num > 1) {
            if (l >= 0 && num - 1 == a[l]) {
                num--;
                l--;
            } else if (r <= n-1 && num - 1 == a[r]) {
                num--;
                r++;
            } else {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
   }

    return 0;
}
