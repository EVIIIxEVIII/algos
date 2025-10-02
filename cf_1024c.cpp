#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int c = n/2;
        vector<vector<int>> grid(n, vector<int>(n));
        int current = n*n - 1;

        for (int i = 0; i < (n+1)/2; ++i) {

            for (int j = i; j < n-i; ++j) {
                grid[i][j] = current--;
            }


        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
