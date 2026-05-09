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
    // it is probably per digit in the sense that say we have 3141,
    // then we for each digits for example 4, we can have 3101, 0040, 0000
    // So we can treat every digit as a bucket and find the number of ways to distribute each
    // digits of our n in 3 buckets? or some shit like that?
    // sticks and starts stuff per digits? so d + 3 - 1 choose 2?

    // 6 * 36 * 3 * 45

    // (d + 2)! / 2!d!

    long long ans = 1;

    long long n;
    cin >> n;

    long long val = n;
    while (val > 0) {
        long long d = val % 10;

        ans *= (d + 2) * (d + 1) / 2;

        val /= 10;
    }

    // tf it actually ACed
    cout << ans << '\n';
}
