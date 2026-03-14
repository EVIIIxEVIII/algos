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
    long long n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the k - 1 minimum cards will be played

    long long ans = 0;
    long long init = a[p];

    multiset<long long> first_k;
    for (long long i = 0; i < k; ++i) {
        first_k.insert(a[i]);
    }

    long long next = k;
    long long rem = p - (k - 1);

    for (long long r = 0; r < rem; ++r) {
        auto it = first_k.begin();

        init += *it;
        first_k.erase(it);

        if (next < n) {
            first_k.insert(a[next++]);
        }
    }

    if (init <= m) {
        ans++;
        m -= init;
    } else {
        cout << 0 << '\n';
        return;
    }

    long long cycle = a[p];
    a.erase(a.begin() + p);
    n--;

    sort(a.begin(), a.end());

    for (long long i = 0; i <= n - k; ++i) {
        cycle += a[i];
    }

    ans += m / cycle;

    cout << ans << '\n';
}
