#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == '.') {
                if (i % 2) {
                    if (j % 2) {
                        b[i][j] = 'B';
                    } else {
                        b[i][j] = 'W';
                    }
                } else {
                    if (j % 2) {
                        b[i][j] = 'W';
                    } else {
                        b[i][j] = 'B';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << '\n';
    }
}
