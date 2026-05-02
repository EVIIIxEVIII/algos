#include <bits/stdc++.h>
#include <numeric>
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

    // we have pref[i] = sum from j = 0 till j = i - 1
    // for some inversion (i, j) the value can be expressed as pref[j] - pref[i]
    //
    // the ideal situation is when for all pref[j] > pref[i] and i < j we have p[i] > p[j] (permutation in (i, j))
    // and for all pref[j] < pref[i] and i < j, p[i] < p[j] is satisfied (no permutation in (i, j))
    //
    // now we can convert this into a global order. For some pref[i] such that pref[i] > pref[j] for all j we want
    // p[i] < p[j] for all j, thus pref[i] gets the smallest possible value, namely 1 etc.

    vector<long long> pref(n);
    pref[0] = 0;

    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i-1] + a[i-1];
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return pref[i] > pref[j];
    });

    vector<int> ans(n);
    int start = 1;
    for (int i = 0; i < n; ++i) {
        ans[idx[i]] = start++;
    }

    for (int val : ans) {
        cout << val << ' ';
    }
    cout << '\n';
}
