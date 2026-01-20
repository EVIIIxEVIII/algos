#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;

        if (n > 31) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }

        if (m > 31) {
            int another_max_ans = (x / (1 << n));
            cout << (1 / (1 << n)) << ' ' << (another_max_ans != 0 ? 1 : 0) << '\n';
            continue;
        }

        int max_ans = ((x / (1 << n)) + (1 << m) - 1) / (1 << m);
        int min_ans = ((x + (1 << m) - 1) / (1 << m)) / (1 << n);

        cout << min_ans << ' ' << max_ans << '\n';
    }
    return 0;
}
