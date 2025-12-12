#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        cout << (n-2)*2 + 1 << '\n';

        for (int i = 2; i < n; ++i) {
            cout << i << ' ' << i << ' ' << n << '\n';
            cout << i << ' ' << 1 << ' ' << n << '\n';
        }

        cout << n << ' ' << 1 << ' ' << n << '\n';


    }
    return 0;
}
