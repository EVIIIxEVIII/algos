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
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // some kind of dp is needed here:
    // when we have 2 random values like 3, 4, the this value can be the start and the end of a segment.
    // if I have a value like 1, 2, then this value can be the end of a segment starting with 1, 1 or starting at some
    // random value like 4, 5, but which contains 1, 1.
    //
    // for a segment like 1, 3 we must know all the starting points L, such that either L = 1, 1 or somewhere between L and R there
    // is a 1, 1
    //
    // Probably we need something like "number of segments which have a 1, 1, or have a 2, 2", or some kind of
    // block abstraction. For example, we can have a block of "random value" such that no one watches any episodes:
    // 2, 3; 3, 4; 3, 2; 4, 3;
    // for every value in this block we can pick it as L or as R, because we don't care so we have:
    // 1, 2, 3, 4 as the number of segments that end at index i. So we can just reduce to:
    // 1 + 2 + 3 + 4. When we see a value like 3, 1 or 1, 4 we must end the random block, but
    // we have to contribute this item to the 1, 1 block, if we see something like 2, 3, the we must
    // end the 1, 1 block and so on.
    //
    // so for a pair a[i], b[i] we must end the block a[i]-1 and block b[i]-1, unless a[i] == b[i], then we
    // may start a block dp[a[i]] = dp[a[i] - 1];

    long long ans = 0;

    vector<int> pa(n + 2, n);
    vector<int> pb(n + 2, n);
    vector<long long> dp(n + 1, n - 1);

    for (int L = n - 1; L >= 0; --L) {
        int aL = a[L];
        int bL = b[L];

        if (aL == bL) {
            int x = aL + 1;

            if (x > n || pa[x] == pb[x]) {
                dp[L] = x > n ? n - 1 : dp[pa[x]];
            } else {
                dp[L] = min(pa[x], pb[x]) - 1;
            }
        }

        pa[aL] = L;
        pb[bL] = L;

        int R;

        if (pa[1] == pb[1]) {
            R = dp[pa[1]];
        } else {
            R = min(pa[1], pb[1]) - 1;
        }

        if (R >= L) {
            ans += R - L + 1;
        }
    }

    cout << ans << '\n';
}
