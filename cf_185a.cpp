#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        long long ans = 0;


        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        if (n == 2) {
            cout << 9 << '\n';
            continue;
        }

        long long c1 = (n*n) + (n*n - 1) + (n*n - 2) + (n*n - n - 1);
        long long c2 = (n*n - 1) + (n*n - n - 1) + (n*n - n - 2) + (n*n - n) + (n*n - 2*n - 1);

        cout << max(c1, c2) << '\n';
    }
    return 0;
}
