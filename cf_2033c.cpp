#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        // fact1: swapping two consecutive a[i] and a[i+1] such that a[i] == a[i+1] is meaningless
        // proof: by def swap(i) := a[i] = a[n - i +1] and a[n - 1 + 1] = a[i], thus
        // a[i], a[i+1] becomes a[n - i], a[n - 1 + 1], and still a[n - i] == a[n - 1 + 1], so
        // a[i] == a[i+1] is preserved by having a[n - 1 + 1] == a[n - i].


        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int l = 1;
        int r = n - 2;

        long long ans = 0;

        while (l < r) {
            int def = 0;
            def += (a[l] == a[l-1]);
            def += (a[r] == a[r+1]);

            int swp = 0;
            swp += (a[l] == a[r+1]);
            swp += (a[r] == a[l-1]);

            if (swp < def) {
                swap(a[l], a[r]);
            }

            l++;
            r--;
        }

        for (int i = 0; i < n - 1; ++i) {
            ans += a[i] == a[i+1];
        }

        cout << ans << '\n';

    }
    return 0;
}
