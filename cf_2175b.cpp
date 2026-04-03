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
    int n, l, r;
    cin >> n >> l >> r;

    // xor works like sums in a prefix xor
    vector<int> prefix(n+1);

    for (int i = 1; i <= n; ++i) {
        prefix[i] = i;
    }

    prefix[l-1] = prefix[r];

    for (int i = 1; i <= n; ++i) {
        cout << (prefix[i] ^ prefix[i-1]) << ' ';
    }
    cout << '\n';
}
