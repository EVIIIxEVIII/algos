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
    long long p, q;
    cin >> p >> q;

    // the difference q - p = d is constant, so we need to check if the point (2d, 3d) is below (p, q),
    // if yes we can reach (2d, 3d) by mirroring Alice's move, because 3d - 2d = d, which is the invariant
    // we hold.

    if (p < q && min(p/2, q/3) >= q - p) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
}
