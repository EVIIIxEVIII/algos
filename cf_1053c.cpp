#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> v(2*n);
        for (int i = 0; i < 2*n; ++i) {
            cin >> v[i];
        }

        vector<long long> ans(n+1);
        for (int i = 0; i < 2*n; i+=2) {
            ans[1] += v[i+1] - v[i];
        }

        if (n == 1) {
            cout << ans[1] << '\n';
            continue;
        }

        ans[2] = ans[1];
        for (int i = 0; i < 2*n-1; ++i) {
            if (i % 2) {
                ans[2] += 2*(v[i+1] - v[i]);
            }
        }

        for (int i = 3; i <= n; ++i) {
            ans[i] = ans[i-2] + 2*(v[2*n - 1 - i+2] - v[i-2]);
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
