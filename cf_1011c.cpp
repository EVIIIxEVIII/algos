#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a == b) {
            cout << -1 << '\n';
            continue;
        }

        if (a < b) swap(a, b);

        long long val = 1 << (64 - __builtin_clzll(a));

        long long ans = val - a;

        cout << ans << '\n';
    }
    return 0;
}
