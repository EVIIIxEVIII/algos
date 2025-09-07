#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = a.size() - 1; i >= 0; i-=2) {
            ans += a[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
