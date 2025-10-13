#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<long long> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<long long> ans(n);
        ans[0] = 1;
        long long counter = 1;

        for (long long i = 1; i < n; ++i) {
            long long need = b[i] - b[i-1];

            ans[i] = (i-need) >= 0 ? ans[i-need] : ++counter;
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
