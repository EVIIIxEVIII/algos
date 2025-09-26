#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        int odd = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            odd += a[i] % 2;
        }

        int maxNum = 0;
        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            maxNum = max(maxNum, a[i]);
            totalSum += a[i];
        }

        if (odd == n || odd == 0) {
            cout << maxNum << '\n';
            continue;
        } else {
            cout << totalSum - odd + 1 << '\n';
        }
    }
    return 0;
}
