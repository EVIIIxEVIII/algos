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
    int x, y;
    cin >> x >> y;

    // so we need two number p and q such that they don't have to same bit set to 1.
    // There are 2 types of bits: ones which can be set for certain in p and q and ones
    // which can be set in either p or q, so our task is to determine these ambiguous
    // bits such that |x - p| + |y - q| is minimized.

    // maybe go from most significant ambiguous bit and try to set it to 1 in p and then in q
    // and compare which one minimizes the value?

    // sometimes it might be beneficial to pick a bit that is to the left of the MSB that is ambiguous

    int p = 0;
    int q = 0;

    vector<int> ambiguous;
    for (int i = 0; i < 32; ++i) {
        int x_set = (x >> i) & 1;
        int y_set = (y >> i) & 1;

        if (x_set && !y_set) {
            p |= (1 << i);
        } else if (!x_set && y_set) {
            q |= (1 << i);
        } else if (x_set && y_set) {
            ambiguous.push_back(i);
        }
    }

    if (ambiguous.empty()) {
        cout << x << ' ' << y << '\n';
        return;
    }

    int b = ambiguous.back();

    int p_msb_set = (p | (1 << b));
    int q_msb_exc = (~(p & ((1 << b) - 1)) & (q | ((1 << b) - 1)));

    int q_msb_set = (q | (1 << b));
    int p_msb_exc = (~(q & ((1 << b) - 1)) & (p | ((1 << b) - 1)));

    int variant1 = abs(x - p_msb_set) + abs(y - q_msb_exc);
    int variant2 = abs(x - p_msb_exc) + abs(y - q_msb_set);

    int variant3 = 0;
    int v3x = 0;
    int v3y = y;
    for (int i = b; i < 32; ++i) {
        int x_b = (x >> i) & 1;
        int y_b = (y >> i) & 1;

        if (x_b || y_b) continue;
        v3x = (x | (1 << i)) & ~((1 << i) - 1);
        variant3 = abs(x - v3x);
        break;
    }

    int variant4 = 0;
    int v4x = x;
    int v4y = 0;
    for (int i = b; i < 32; ++i) {
        int x_b = (x >> i) & 1;
        int y_b = (y >> i) & 1;
        if (x_b || y_b) continue;
        v4y = (y | (1 << i)) & ~((1 << i) - 1);
        variant4 = abs(y - v4y);
        break;
    }

    int min_var = min({ variant1, variant2, variant3, variant4 });

    if (min_var == variant1) {
        cout << p_msb_set << ' ' << q_msb_exc << '\n';
    } else if (min_var == variant2) {
        cout << p_msb_exc << ' ' << q_msb_set << '\n';
    } else if (min_var == variant3) {
        cout << v3x << ' ' << v3y << '\n';
    } else {
        cout << v4x << ' ' << v4y << '\n';
    }
}
