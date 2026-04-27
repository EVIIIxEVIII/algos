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

    string s;
    cin >> s;

    int q;
    cin >> q;

    // I need a total xor for values at 0 and values at 1.
    // keep a prefix/suffix xor for the 0 ones and 1 ones and then
    // when a type 1 query is received we can get the xor from l to r in
    // both prefix xors and xor each xor with their respective pool.
    // For example:
    // 1 1 5
    // we get the xor from 1 to 5 from the 0_prefix/0_suffix and in the 1_prefix/1_suffix
    // we then xor the values we got with the pools, i.e we xor the value we got from 0_prefix/0_suffix
    // with both pool_1 and pool_0, and thus all the values get removed from 0 and get added to 1, and when the next l, r
    // query hits this process is reversed.

    vector<int> prefix_0(n+1);
    vector<int> prefix_1(n+1);
    prefix_0[0] = 0;

    int pool_0 = 0;
    int pool_1 = 0;

    for (int i = 1; i <= n; ++i) {
        prefix_1[i] = prefix_1[i-1];
        prefix_0[i] = prefix_0[i-1];
        if (s[i-1] == '0') {
            prefix_0[i] ^= a[i-1];
            pool_0 ^= a[i-1];
        } else {
            prefix_1[i] ^= a[i-1];
            pool_1 ^= a[i-1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            int xor_0 = prefix_0[r] ^ prefix_0[l-1];
            int xor_1 = prefix_1[r] ^ prefix_1[l-1];

            pool_0 = pool_0 ^ xor_0 ^ xor_1;
            pool_1 = pool_1 ^ xor_0 ^ xor_1;
        } else {
            int pool;
            cin >> pool;

            if (pool == 0) {
                cout << pool_0 << ' ';
            } else {
                cout << pool_1 << ' ';
            }
        }
    }

    cout << '\n';
}
