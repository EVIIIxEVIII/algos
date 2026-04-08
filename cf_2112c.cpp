#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    int max_el = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_el = max(max_el, a[i]);
    }

    // Bob will always pick max(a[i])
    // for every pair check the number of other numbers a[i] except max(a[i]) such that a + b + c > max(a)
    // we can do this using a b-search upper_bound and decreasing the index if a[i] or a[j] are in that upper region.
    // at the end we get O(n^2*log(n)) which should be ok for n = 5000.

    sort(a.begin(), a.end());
    long long ans = 0;

    for (int k = 2; k < n; ++k) {
        int need = max(max_el - a[k], a[k]);
        int i = 0;
        int j = k - 1;

        while (i < j) {
            if (a[i] + a[j] > need) {
                ans += j - i;
                j--;
            } else {
                ++i;
            }
        }
    }

    cout << ans << '\n';
}
