#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> centers(n);
        for(int i = 0; i < n; ++i) {
            cin >> centers[i];
        }

        vector<int> radii(n);
        for(int i = 0; i < n; ++i) {
            cin >> radii[i];
        }

        // (x - x_i)^2 + y^2 <= r^2
        // y^2 <= r^2 - (x - x_i)^2
        // -sqrt(r^2 - (x - x_i)^2) <= y <= sqrt(r^2 - (x - x_i)^2)

        map<long long, long long> cnt;

        for (int i = 0; i < n; ++i) {
            long long x_i = centers[i];
            long long r_i = radii[i];

            for (long long x = x_i - r_i; x <= x_i + r_i; ++x) {
                if ((x - x_i) * (x - x_i) > r_i * r_i) {
                    continue;
                }

                long long a = sqrt(r_i * r_i - (x - x_i) * (x - x_i));
                cnt[x] = max(cnt[x], 2LL*a+1);
            }
        }

        long long ans = 0;

        for (auto [x, c] : cnt) {
            ans += c;
        }

        cout << ans << '\n';
    }

    return 0;
}
