#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int a; cin >> a;
        int b; cin >> b;
        int x; cin >> x;
        int y; cin >> y;

        if (a - 1 == b && a % 2) {
            cout << y << '\n';
            continue;
        }

        long long ans = 0;
        if (a > b) {
            cout << -1 << '\n';
            continue;
        } else {
            if (y > x) {
                cout << (b - a) * x << '\n';
                continue;
            }

            while (a != b) {
                if (a % 2 == 0) {
                    ans += y;
                    a += 1;
                } else {
                    ans += x;
                    a += 1;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
