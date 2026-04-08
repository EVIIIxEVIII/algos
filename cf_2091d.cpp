#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    // 1 0 1 0 1 -> (5 + 1) / 2 = 3
    // 1 0 1 0 -> (4 + 1) / 2 = 2

    // 1 1 0 1 1 -> 5 / 3 = 1, 5 % 3 = 2
    // 1 1 0 1 -> 4 / 3 = 1, 4 % 3 = 1

    // 1 1 0 1 1

    // 2 4 7
    // 4 / 3 + 4 % 3 = 1 + 1 = 2
    // 5 / 3 + 5 % 3

    // FFFFTTT
    int l = 0;
    int r = m;

    while (l < r) {
        long long mid = l + (r - l)/2;

        long long total = ((m / (mid + 1)) * mid + (m % (mid + 1))) * n;
        if (total < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << r << '\n';
}
