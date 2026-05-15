#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    long long n, q;
    cin >> n >> q;

    n = (1 << n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int,int>> b(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i].first;
        cin >> b[i].second;
    }

// tf binary search with xors???
// we can directly simulate this thing, the only hard thing is tracking this special position
// for each q. Assume for q_i the position is some i, if i <= n/2 then i will be in the first stack
// otherwise in the second one, we can compute the xor of both parts very easily and see in which one that
// position will be located, then we can do that with the 4th, and the 8th and thus obtain the final position.

    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] ^ a[i-1];
    }

    auto pos = [&](auto&& self, int idx, int l, int r, int was, int is) {
        if (r - l == 1) return 0;

        int m = l + (r - l) / 2;
        int ans = 0;

        int left = prefix[m] ^ prefix[l];
        int right = prefix[r] ^ prefix[m];

        if (idx < m) {
            left ^= was;
            left ^= is;
        } else {
            right ^= was;
            right ^= is;
        }

        int n_l = idx < m ? l : m;
        int n_r = idx < m ? m : r;

        if ((idx < m && left >= right) || (idx >= m && right > left)) {
            ans += self(self, idx, n_l, n_r, was, is);
        } else {
            ans += m - l;
            ans += self(self, idx, n_l, n_r, was, is);
        }

        return ans;
    };

    for (int i = 0; i < q; ++i) {
        auto [p, c] = b[i];
        cout << pos(pos, p - 1, 0, n, a[p-1], c) << '\n';
    }
}
