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

    auto eq = [&](long long i, long long j) -> bool {
        return p % 2LL == i && q % 3LL == j;
    };

    if (eq(0, 2) || eq(0, 0) || eq(1, 1) || eq(0, 1)) {
        cout << "bob" << '\n';
    } else {
        cout << "alice" << '\n';
    }
}
