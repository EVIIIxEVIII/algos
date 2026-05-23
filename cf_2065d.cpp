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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<pair<long long,int>> scores(n);

    for (int i = 0; i < n; ++i) {
        long long score = 0;
        for (int j = 0; j < m; ++j) {
            score += a[i][j];
        }

        scores[i] = {score, i};
    }

    sort(scores.begin(), scores.end(), greater<pair<long long, int>>());

    vector<long long> ans;
    for (auto [s, i] : scores) {
        for (int j = 0; j < m; ++j) {
            ans.push_back(a[i][j]);
        }
    }

    assert((int)ans.size() == n * m);

    vector<long long> prefix_ans(n * m);
    prefix_ans[0] = ans[0];

    for (int i = 1; i < n * m; ++i) {
        prefix_ans[i] = prefix_ans[i-1] + ans[i];
    }

    long long score = 0;
    for (long long v : prefix_ans) {
        score += v;
    }

    cout << score << '\n';
}
