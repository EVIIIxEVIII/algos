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
    int n, k;
    cin >> n >> k;


    //bool rem = false;

    //for (int i = 0; i < 31; ++i) {
    //    if ((n >> i) == k) {
    //        cout << i << '\n';
    //        return;
    //    }

    //    if (rem && (n >> i) + 1 == k) {
    //        cout << i << '\n';
    //        return;
    //    }

    //    rem |= (n >> i) & 1;
    //}

    bool rem = false;

    int fac = 1;
    int t = 0;
    while ((n / fac) > 0) {
        if (n / fac == k) {
            cout << t << '\n';
            return;
        }

        if (rem && (n / fac) + 1 == k) {
            cout << t << '\n';
            return;
        }

        if ((n / fac) % 2 != 0) {
            rem = true;
        }

        fac *= 2;
        t++;
    }

    cout << -1 << '\n';
}
