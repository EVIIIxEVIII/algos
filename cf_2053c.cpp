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
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    long long inter = n;
    long long add = 0;

    while (inter >= k) {
        if (inter & 1) {
            long long l = (inter >> 1) + 1;
            long long r = n - (inter >> 1) - 1;

            long long count = (r - l) / inter + 1;

            long long sum = (count * (l + r)) / 2;
            ans += sum;
            add++;
        }

        inter >>= 1;
    }

    cout << ans << '\n';
}
