#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    vector<pair<int,int>> a_map(n * m + 1);
    vector<pair<int,int>> b_map(n * m + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    // row a_r1 must contain the same elements as row b_r1 and column
    // a_c1 must contain the same elements as column b_c1 and this must be true
    // for all rows and for all columns.

    vector<string> a_rows;
    unordered_set<string> b_rows;

    vector<string> a_cols;
    unordered_set<string> b_cols;

    for (int i = 0; i < n; ++i) {
        vector<int> a_row = a[i];
        vector<int> b_row = b[i];

        sort(a_row.begin(), a_row.end());
        sort(b_row.begin(), b_row.end());

        string a_row_s;
        a_row_s.resize(m);
        string b_row_s;
        b_row_s.resize(m);
        for (int j = 0; j < m; ++j) {
            a_row_s[j] = a_row[j]-'0';
            b_row_s[j] = b_row[j]-'0';
        }

        a_rows.push_back(a_row_s);
        b_rows.insert(b_row_s);
    }

    for (int j = 0; j < m; ++j) {
        vector<int> a_col;
        vector<int> b_col;

        for (int i = 0; i < n; ++i) {
            a_col.push_back(a[i][j]);
            b_col.push_back(b[i][j]);
        }

        sort(a_col.begin(), a_col.end());
        sort(b_col.begin(), b_col.end());

        string a_col_s;
        a_col_s.resize(n);
        string b_col_s;
        b_col_s.resize(n);

        for (int i = 0; i < n; ++i) {
            a_col_s[i] = a_col[i]-'0';
            b_col_s[i] = b_col[i]-'0';
        }

        a_cols.push_back(a_col_s);
        b_cols.insert(b_col_s);
    }

    for (const auto& row : a_rows) {
        if (!b_rows.contains(row)) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (const auto& col : a_cols) {
        if (!b_cols.contains(col)) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
