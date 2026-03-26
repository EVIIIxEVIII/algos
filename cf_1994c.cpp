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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // the idea is to probably compute the reverse: the number
    // of segments where we have 0 at the end and then subtract that
    // value from the total number of possible segments.
    // prefix + suffix sum?
    //
    // O(n^2) solution: for each l compute a prefix sum from l to n - 1, then
    // count the number of number in the prefix sum such that p[i] %


}
