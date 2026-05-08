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
    int h, w, x_a, y_a, x_b, y_b;
    cin >> h >> w >> x_a >> y_a >> x_b >> y_b;

    if (x_a >= x_b) {
        cout << "Draw" << '\n';
        return;
    }

    // first of all x_a <= x_b otherwise it is a draw automatically.
    // if abs(y_a - y_b) is too big it is a draw too.
    //
    // x parity matters, if abs(x_a - x_b) % 2 == 1 then
    // Alice wins unless the y distance is too big otherwise Bob wins.
    //
    // if abs(y_a - y_b) <= 1 then the winner wins
    // otherwise (assume for Bob winning) we need
    // abs(y_a - y_b) + min(w - y_a, y_a) <= abs(x_a - x_b) but somewher should be
    // either a *2 or /2 because the distance is removed only by the loosing person

    int dx = abs(x_b - x_a);

    if (dx % 2 == 1) { // Alice makes (dx + 1) / 2 moves
        int a = (dx + 1) / 2;
        int b = dx / 2;

        int al = max(1, y_a - a);
        int ar = min(w, y_a + a);

        int bl = max(1, y_b - b);
        int br = min(w, y_b + b);

        if (al <= bl && br <= ar) {
            cout << "Alice" << '\n';
        } else {
            cout << "Draw" << '\n';
        }
    } else {
        int t = dx / 2;

        int al = max(1, y_a - t);
        int ar = min(w, y_a + t);

        int bl = max(1, y_b - t);
        int br = min(w, y_b + t);

        if (bl <= al && ar <= br) {
            cout << "Bob" << '\n';
        } else {
            cout << "Draw" << '\n';
        }
    }


}
