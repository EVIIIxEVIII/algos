#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int a, b = 0;

        for (int i = 2; i*i < n; ++i) {
            if (n % i == 0) {
                a = i;
                n /= a;
                break;
            }
        }

        if (!a) {
            cout << "NO" << '\n';
            continue;
        }

        for (int i = a+1; i*i < n; ++i) {
            if (n % i == 0) {
                b = i;
                n /= b;
                break;
            }
        }

        if (!b) {
            cout << "NO" << '\n';
            continue;
        }

        if (n == 1 || n == a || n == b) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        cout << a << ' ' << b << ' ' << n << '\n';
    }
    return 0;
}
