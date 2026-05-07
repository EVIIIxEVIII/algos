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

constexpr long long mod = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> a(k);
    for (int i = 0 ; i < k ;++i) {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    // if a cell is a non diagonal
    // then it contributes 2 possible configurations: first one when (r, c) is black and (c, r) is white or vice versa.
    // otherwise only one configuration.
    //
    // assume the problem simplifies to a (n - moves) x (n - moves) grid
    // if the statement above is somehow true, picking 2 diagonal c == r cells would be equivalent to
    // picking one non diagonal cell c != r, because the grid size will be reduced by 2 in both cases.
    //
    // so the answer after picking 2 diagonal moves and 1 non diagonal move should be the same?
    //
    // So the problem becomes finding out the number of configurations for dp[i] where i is the number of reamining free
    // rows and free columns. If the above statement is true:
    // dp[i] = dp[i-1] + dp[i-2] * 2 * (i - 1); -> either use a diagonal number or use a non diagonal one,
    // there is one diagonal one (top left corner) and i - 1 non diagonals (the other ones without the diagonal one)

    int count = n;
    for (int i = 0; i < k; ++i) {
        if (a[i].first == a[i].second) {
            count--;
        } else {
            count -= 2;
        }
    }

    vector<long long> dp(max(count + 1, 3));

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= count; ++i) {
        dp[i] = (dp[i-1] + ((2 * (i-1) % mod) * dp[i-2] % mod)) % mod;
    }

    cout << dp[count] << '\n';
}
