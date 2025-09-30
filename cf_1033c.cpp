#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long m; cin >> m;

        long long minSum = n;
        long long maxSum = n*(n+1) / 2;

        if (m < minSum || m > maxSum) {
            cout << -1 << '\n';
            continue;
        }

        set<int> used;
        long long missing = m - n;
        long long current = 0;

        vector<int> ans;

        for (int i = n - 1; i > 0; --i) {
            if (current + i <= missing) { // not adding 1 to i, because 1 is by default in n
                ans.push_back(i+1);
                current += i;
                used.insert(i+1);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!used.count(i)) {
                ans.push_back(i);
            }
        }

        cout << ans[0] << '\n';
        for (int i = 0; i < n-1; ++i) {
            cout << ans[i] << ' ' << ans[i+1] << '\n';
        }
    }
    return 0;
}
