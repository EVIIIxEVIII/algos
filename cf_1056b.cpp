#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;

        if (n*n - k == 1) {
            cout << "NO" << '\n';
            continue;
        }

        int left = k;
        int last = true;

        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (left > 0) {
                    cout << 'U';
                    left--;
                } else {
                    if (last && j == n-1) {
                        cout << 'D';
                    } else if (j == n-1) {
                        cout << 'L';
                    } else {
                        cout << 'R';
                    }

                    last = false;
                }
            }

            cout << '\n';
        }


    }
    return 0;
}
