#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        long long sum = n * (n + 1) / 2;
        long long r = std::llround(std::sqrt(sum));

        if (r*r == sum) {
            cout << -1 << '\n';
            continue;
        }

        for (long long i = 1; i <= n;) {
            long long sum = i * (i + 1) / 2;
            long long r = std::llround(std::sqrt(sum));

            if (r*r == sum && i+1 <= n) {
                cout << i+1 << ' ';
                cout << i << ' ';
                i += 2;
            } else {
                cout << i << ' ';
                ++i;
            }
        }

        cout << '\n';
    }
    return 0;
}
