#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // key take away:
    // the distance in a directed graph is computed using the direction of the arrow
    // so if you have x_i -> y_i, the distance from x_i to y_i is 1, but the vice versa is not
    // generally true

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> x(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
        }

        vector<int> cnt(n+1);
        for (int i = 1; i <= n; ++i) {
            cnt[x[i]]++;
        }

        int from = -1;
        int to = -1;

        for (int i = 1; i <= n; ++i) {
            if (!cnt[i]) {
                from = i;
            } else {
                to = i;
            }
        }

        if (from != -1) {
            cout << "? " << from << ' ' << to << '\n';
            cout.flush();
            int ans1;
            cin >> ans1;
            if (ans1 == -1) {
                exit(1);
            }

            if (ans1 == 0) {
                cout << "! A" << '\n';
            } else {
                cout << "! B" << '\n';
            }
            cout.flush();
            continue;
        }

        int min_i = 1;
        int max_i = 1;

        for (int i = 1; i <= n; ++i) {
            if (x[i] < x[min_i]) {
                min_i = i;
            }

            if (x[i] > x[max_i]) {
                max_i = i;
            }
        }

        cout << "? " << min_i << ' ' << max_i << '\n';
        cout.flush();
        int ans1;
        cin >> ans1;
        if (ans1 == -1) {
            exit(1);
        }

        cout << "? " << max_i << ' ' << min_i << '\n';
        cout.flush();
        int ans2;
        cin >> ans2;
        if (ans2 == -1) {
            exit(1);
        }

        if (ans1 == ans2 && ans1 >= n - 1 && ans2 >= n - 1) {
            cout << "! B" << '\n';
        } else {
            cout << "! A" << '\n';
        }

        cout.flush();
    }
    return 0;
}
