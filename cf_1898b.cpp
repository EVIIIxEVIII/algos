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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_so_far = a[n-1];
    long long ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > min_so_far) {
            int k = (a[i] + min_so_far - 1) / min_so_far;
            ans += k - 1;
            min_so_far = a[i] / k;
        } else {
            min_so_far = a[i];
        }
    }

    cout << ans << '\n';
}
