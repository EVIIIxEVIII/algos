#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a[0] == 1) {
            cout << a[0] << ' ' << a[1] << '\n';
            continue;
        }

        int a1 = -1;
        int a2 = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0 && a1 == -1) {
                a1 = a[i];
            } else if (a[i] % 2 == 0 && a1 != -1) {
                a2 = a[i];
                break;
            }
        }

        if (a1 != -1 && a2 != -1) {
            cout << a1 << ' ' << a2 << "\n";
            continue;
        }

        for (int i = 0; i < n-1; ++i) {
            if (a[i] % 2 == 1 && a[i] * 2LL > a[i+1] && (a[i+1] - a[i]) % 2 == 0) {
                a1 = a[i];
                a2 = a[i+1];
                break;
            }
        }

        if (a1 != -1 && a2 != -1) {
            cout << a1 << ' ' << a2 << "\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (a1 != -1 && a2 != -1) break;
            if (a[i] % 2 == 0) continue;

            for (int j = i+1; j < n; ++j) {
                if ((a[j] % a[i]) % 2 == 0) {
                    a1 = a[i];
                    a2 = a[j];
                    break;
                }
            }
        }

        if (a1 != -1 && a2 != -1) cout << a1 << ' ' << a2 << "\n";
        else cout << -1 << '\n';
    }
    return 0;
}
