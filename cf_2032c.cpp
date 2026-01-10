#include <bits/stdc++.h>
#include <climits>
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

        sort(a.begin(), a.end());

        // main idea:
        // this could be solved in nlog(n) by doing binary search, but the editorial solution is O(n)
        // Basically if there is a monotonic condition, like here were r++ is always worse, then two pointers
        // technique can be used. So here we can fix the r from a[l] + a[l+1] > a[r] and only march forward using l.
        // The idea is that if I increase r, then I am allowed not to decrease l, because that l-1 didn't work for r-1, and
        // thus it won't work on r.

        int ans = n - 2;
        int l = 0;
        for (int r = 2; r < n; ++r) {
            while (r - l >= 2 && a[l] + a[l+1] <= a[r]) {
                l++;
            }
            ans = min(ans, n - (r - l+ 1));
        }

        cout << ans << '\n';
    }
    return 0;
}
