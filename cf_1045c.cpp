#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // 0 0 3 3
        // 0 2 2 7
        //
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                int prev = a[i-1];
                int next = i+1 <= n ? a[i+1] : 0;

                if (prev > a[i]) {
                    a[i-1] -= prev - a[i];
                    ans += prev - a[i];
                }

                if (next > a[i]) {
                    a[i+1] -= next - a[i];
                    ans += next - a[i];
                }

                int left = a[i-1] + (i+1 <= n ? a[i+1] : 0) - a[i];

                if (left > 0) {
                    ans += left;
                    if (i + 1 <= n) {
                        int take = min(a[i+1], left);
                        a[i+1] -= take;
                        left -= take;
                    }

                    if (left > 0 && i - 1 >= 1) {
                        int take = min(a[i-1], left);
                        a[i-1] -= take;
                        left -= take;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
