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
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<int> x(m);

    vector<long long> odd;
    vector<long long> even;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
        if ((i + 1) % 2) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }

    sort(odd.begin(), odd.end(), greater<long long>());
    sort(even.begin(), even.end(), greater<long long>());

    int o = 0;
    int e = 0;

    for (int i = 0; i < m; ++i) {
        if (x[i] % 2 && o < (int)odd.size()) {
            if (o == 0 || odd[o] > 0) {
                ans -= odd[o];
                o++;
            }
        } else if (x[i] % 2 == 0 && e < (int)even.size()) {
            if (e == 0 || even[e] > 0) {
                ans -= even[e];
                e++;
            }
        }
    }

    cout << ans << '\n';
}
