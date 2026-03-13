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
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = l;

    vector<int> dis(n+1);
    dis[0] = a[0];

    for (int i = 1; i <= n; ++i) {
        dis[i] = a[i] - a[i-1];
    }

    // maybe only the last m a[i] matter? because the last segment should be split into 2 danger levels
    // the one before that should be split into 3 danger levels and the one before into 4 danger levels.
    // This is because one of the values will be destoroyed anyways after each a[i], so it would make sense to
    // split the danger levels in this way.

    long long ans = 0;


    for (int i = n; i >= max(n - m + 2, 0); --i) {
        int div = n - i + 1;

        ans += dis[i] / div;
    }

    for (int i = 0; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    cout << ans << '\n';
}
