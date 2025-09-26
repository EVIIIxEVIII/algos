#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int ks = 0;

        vector<int> missing(k, true);
        for (int i = 0; i < n; ++i) {
            if (a[i] == k) ks++;
            if (a[i] < k) missing[a[i]] = false;
        }

        int missingNum = 0;
        for (int i = 0; i < k; ++i) {
            if (missing[i]) {
                missingNum++;
            }
        }

        cout << max(missingNum, ks) << '\n';
    }
    return 0;
}
