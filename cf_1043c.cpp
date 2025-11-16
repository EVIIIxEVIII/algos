#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;

        long long ans = 0;
        while (n > 0) {
            long long m = 1;
            long long x = 0;
            while (m*3 <= n) {
                m *= 3;
                x++;
            }

            n -= m;

            long long firstPart = 1;
            for (int i = 0; i < x; ++i) {
                firstPart *= 3;
            }
            firstPart *= 3;

            long long secondPart = 1;
            for (int i = 0; i < x-1; ++i) {
                secondPart *= 3;
            }
            secondPart *= x;

            ans += (firstPart + secondPart);
        }

        cout << ans << '\n';
    }
    return 0;
}
