#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;

        if (x > y) {
            swap(x, y);
        }

        if (a >= x && a <= y) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }


    }
    return 0;
}
