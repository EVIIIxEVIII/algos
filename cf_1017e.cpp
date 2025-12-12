#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> cnt(31);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 31; ++j) {
                cnt[j] += (a[i] >> j) & 1;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long localAns = 0;
            for (int j = 0; j < 31; ++j) {
                if ((a[i] >> j) & 1) {
                    localAns += (1LL << j) * (n - cnt[j]);
                } else {
                    localAns += (1LL << j) * cnt[j];
                }
            }

            ans = max(ans, localAns);
        }

        cout << ans << '\n';
    }


    return 0;
}
