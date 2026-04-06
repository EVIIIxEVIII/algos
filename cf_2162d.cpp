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
    long long n; cin >>n;

    // 1 l r - original
    // 2 l r - changed
    // ! l r - output cout.flush()

    // 2 binary searches: one for l and the other one for r
    // the one for l is TTFF style
    // the one for r is FFTT style
    // mid = (l + r) / 2; l = mid + 1; r = mid; finds the first point where the condition is false
    // mid = (l + r + 1) / 2; l = mid; r = mid - 1; finds the last point where the condition is true

    int l = 0;
    int r = n;

    // TTFF
    while (l < r) {
        int m = l + (r - l + 1) / 2;

        cout << 1 << ' ' << 1 << ' ' << m << '\n';
        cout.flush();
        long long x; cin >> x;

        cout << 2 << ' ' << 1 << ' ' << m << '\n';
        cout.flush();
        long long y; cin >> y;

        if (x != y) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    int ans_l = l+1;

    long long sum = 0;
    cout << 2 << ' ' << 1 << ' ' << n << '\n';
    cout.flush();
    cin >> sum;

    long long original_sum = (n + 1) * n / 2;
    long long length = sum - original_sum;

    int ans_r = ans_l + length - 1;

    cout << '!' << ' ' << ans_l << ' ' << ans_r << '\n';
    cout.flush();
}
