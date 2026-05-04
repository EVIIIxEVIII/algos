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
    long long r;
    cin >> r;

    // the number of latice points stricly inside the circle with radius r + 1?
    // x^2 + y^2 < (r+1)^2 => x^2 < (r+1)^2 - y^2 => x < sqrt((r+1)^2 - y^2)
    // then go through 1 <= y < r and check for x? but multiply by 2 for the symmetric thing on the other side?

    long long total = 0;
    for (long long y = 0; y < (r+1); ++y) {
        long long val = (r+1)*(r+1) - y*y;
        long long xes = sqrt(val - 1);

        long long row = xes * 2 + 1;
        if (y == 0) {
            total += row;
        } else {
            total += row * 2;
        }
    }
    total--;

    long long exclude = 0;
    for (long long y = 0; y < r; ++y) {
        long long val = r * r - y * y;
        long long xes = sqrt(val - 1);

        long long row = xes * 2 + 1;

        if (y == 0) {
            exclude += row;
        } else {
            exclude += row * 2;
        }
    }
    exclude--;

    cout << total - exclude << '\n';
}
