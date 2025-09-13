#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = 0;

        vector<int> odd;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                ans += a[i];
            } else {
                odd.push_back(a[i]);
            }
        }

        sort(odd.begin(), odd.end(), greater<int>());

        if (odd.size() == 0) {
            ans = 0;
        }

        for (int i = 0; i < (odd.size() + 1) / 2; ++i) {
            ans += odd[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
