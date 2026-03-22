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
    int n, m;
    cin >> n >> m;

    long long ones_cnt = 0;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 1) ones_cnt++;
        }
    }

    // we have let k be the number of 1s in the grid, x -> the number of ones on the left side
    // and y -> the number of ones on the right side, such that x + y = k. Then x * y is maximized
    // when x = n / 2 and y = n / 2 (+ 1 if n is odd).

    // let's assume such a cut is always possible.

    // we can sort by how "left" and how "down" the ones are and then use them as ones in the left part.
    // The coordinates of the most "right" such elements will be used to draw the delimited.

    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                pq.push({ m - j - 1, i });
            }
        }
    }

    vector<pair<int,int>> left;
    for (int k = 0; k < ones_cnt/2; ++k) {
        auto [j, i] = pq.top();
        j = m - j - 1;

        pq.pop();

        left.push_back({i, j});
    }

    sort(left.begin(), left.end());

    vector<int> per_row(n, -1);
    int max_r = -1;
    for (auto& [i, j] : left) {
        per_row[i] = max(max_r, j+1);
    }

    int c_i = 0;
    int c_j = 0;

    cout << (ones_cnt/2) * (ones_cnt/2 + ones_cnt%2) << '\n';

    for (int i = 0; i < n; ++i) {
        if (per_row[i] == -1) continue;

        while (c_i < i) {
            cout << 'D';
            c_i++;
        }

        while (c_j < per_row[i]) {
            cout << 'R';
            c_j++;
        }
    }

    while (c_i < n) {
        cout << 'D';
        c_i++;
    }

    while (c_j < m) {
        cout << 'R';
        c_j++;
    }

    cout << '\n';
}
