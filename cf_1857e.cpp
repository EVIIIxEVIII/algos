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

    vector<pair<long long,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    // assume elements are unique
    // the for some segment [a[i], a[j]] then
    // when moving from a[i] to a[i+1] the only multiplier that changes
    // is for the region [a[i-1], a[i]] and [a[i], a[i+1]], others stay constant
    // so if we know that the multiplier of [a[i], a[i+1]] we can remove that
    // value from the precomputed suffix sum and then add it to the prefix sum
    // by multiplying this [a[i], a[i+1]] by the correct multiplier which is
    // the index of this segment from left to right.

    vector<long long> ans(n);
    long long cur = n;

    for (int i = 1; i < n; ++i) {
        cur += (a[i].first - a[0].first);
    }
    ans[a[0].second] = cur;

    for (int i = 1; i < n; ++i) {
        long long gap = a[i].first - a[i - 1].first;
        cur -= gap * (n - i);
        cur += gap * i;
        ans[a[i].second] = cur;
    }

    for (long long ans_i : ans) {
        cout << ans_i << ' ';
    }

    cout << '\n';
}
