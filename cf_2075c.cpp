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
    long long n, m;
    cin >> n >> m;

    vector<long long> a(m);
    for (long long i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // idea for every cut check the number of ways using b-search
    // only half?

    long long ans = 0;
    for (long long l = 1; l < n; ++l) {
        // l <= r
        long long r = n - l;

        long long count_l = a.end() - lower_bound(a.begin(), a.end(), l);
        long long count_r = a.end() - lower_bound(a.begin(), a.end(), r);

        if (count_l < count_r) {
            swap(count_l, count_r);
        }

        ans += ((count_l - count_r) * count_r + count_r * (count_r - 1));
    }

    cout << ans << '\n';
}

