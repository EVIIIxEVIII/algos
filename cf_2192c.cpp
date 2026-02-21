#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, h, k;
        cin >> n >> h >>k;

        long long sum = 0;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        long long ans = 0;
        long long cycles = h / sum;
        ans += cycles * n;

        if (cycles > 0) {
            ans += (cycles - 1) * k;
        }

        if (h % sum == 0) {
            cout << ans << '\n';
            continue;
        } else if (h / sum != 0) {
            ans += k;
        }

        h = h % sum;

        vector<long long> prefix(n);
        prefix[0] = a[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + a[i];
        }

        vector<long long> suffix_max(n);
        suffix_max[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suffix_max[i] = max(a[i], suffix_max[i+1]);
        }

        vector<long long> prefix_min(n);
        prefix_min[0] = a[0];

        for (int i = 1; i < n; ++i) {
            prefix_min[i] = min(prefix_min[i-1], a[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (prefix[i] >= h) {
                ans += i+1;
                break;
            }

            if (i < n-1) {
                long long best =
                    prefix[i] - prefix_min[i] + suffix_max[i+1];

                if (best >= h) {
                    ans += i+1;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
