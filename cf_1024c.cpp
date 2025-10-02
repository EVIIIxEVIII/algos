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

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; ++j) {
                grid[top][j] = current--;
            }

            top++;
            if (top > bottom) break;

            for (int j = top; j <= bottom; ++j) {
                grid[j][right] = current--;
            }

            right--;
            if (left > right) break;

            for (int j = right; j >= left; --j) {
                grid[bottom][j] = current--;
            }

            bottom--;
            if (top > bottom) break;

            for (int j = bottom; j >= top; --j) {
                grid[j][left] = current--;
            }

            left++;
            if (left > right) break;
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
