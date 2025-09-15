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

        int totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += a[i];
        }

        bool stop = false;
        int prefix = 0;
        for (int l = 0; l < n-1; ++l) {
            prefix += a[l];

            int mid = 0;
            for (int r = l+1; r < n-1; ++r) {
                mid += a[r];

                int r1 = prefix % 3;
                int r2 = mid % 3;
                int r3 = (totalSum - (mid + prefix)) % 3;

                if (r1 == r2 && r2 == r3) {
                    stop = true;
                    cout << l+1 << ' ' << r+1 << '\n';
                    break;
                } else if (
                    r1 != r2 &&
                    r2 != r3 &&
                    r1 != r3
                ) {
                    stop = true;
                    cout << l+1 << ' ' << r+1 << '\n';
                    break;
                }
            }

            if (stop) break;
        }

        if (!stop) cout << 0 << ' ' << 0 << '\n';
   }

    return 0;
}
