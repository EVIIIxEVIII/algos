#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_i = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == n) {
                max_i = i;
                break;
            }
        }

        cout << n << ' ';
        for (int i = 1; i < n; ++i) {
            if (i == max_i) {
                cout << a[0] << ' ';
            } else {
                cout << a[i] << ' ';
            }
        }

        cout << '\n';
    }
    return 0;
}
