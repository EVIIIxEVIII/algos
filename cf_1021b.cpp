#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        cout << a[(n + k) / 2] - a[(n - k - 1) / 2] + 1 << '\n';
    }
    return 0;
}
