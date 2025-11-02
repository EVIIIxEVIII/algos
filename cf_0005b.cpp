#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid(n);

        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        bool ans = true;
        for (int i = 0; i < n; ++i) {
            int start = -1;
            int finish = -1;

            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '#') {
                    if (start == -1) start = j;
                    finish = j;
                }
            }

            if (start != -1 && finish != -1) {
                ans = (finish - start) > 1 ? false : ans;
            }
        }

        for (int j = 0; j < n; ++j) {
            int start = -1;
            int finish = -1;

            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == '#') {
                    if (start == -1) start = i;
                    finish = i;
                }
            }

            if (start != -1 && finish != -1) {
                ans = (finish - start) > 1 ? false : ans;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';

    }
    return 0;
}
