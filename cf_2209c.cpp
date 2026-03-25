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
}
