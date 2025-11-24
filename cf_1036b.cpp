#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a[0] > a[1]) {
            cout << a[0] + a[1] << '\n';
            continue;
        } else {
            cout << a[0] * 2 << '\n';
        }
    }
    return 0;
}
