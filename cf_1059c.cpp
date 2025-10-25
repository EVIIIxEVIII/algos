#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;

        if (__builtin_clz(a) > __builtin_clz(b)) {
            cout << -1 << '\n';
            continue;
        }

        cout << 2 << '\n';
        int temp = (1 << (32 - __builtin_clz(a))) - 1;
        cout << (a ^ temp) << ' ';
        a = temp;

        int ans = 0;
        for (int i = 0; i < 32 - __builtin_clz(a); ++i) {
            ans |= ((a >> i) ^ (b >> i)) << i;
        }

        cout << ans << '\n';
    }
    return 0;
}
