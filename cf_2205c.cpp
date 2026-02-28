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
    int n;
    cin >> n;

    vector<vector<int>> b(n);

    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        unordered_set<int> seen;

        vector<int> temp(l);
        for (int j = l-1; j >= 0; j--) {
            int val; cin >> val;
            temp[j] = val;
        }

        for (int j = 0; j < l; ++j) {
            if (!seen.contains(temp[j])) {
                b[i].push_back(temp[j]);
                seen.insert(temp[j]);
            }
        }
    }

    unordered_set<int> seen;
    vector<bool> used(n, false);
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        vector<int> best;
        int best_idx = -1;

        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;

            vector<int> current;
            for (auto pers : b[j]) {
                if (!seen.contains(pers)) {
                    current.push_back(pers);
                }
            }
            if (best_idx == -1 || current < best) {
                best = std::move(current);
                best_idx = j;
            }
        }

        if (best_idx != -1) {
            used[best_idx] = true;

            for (auto x : best) {
                ans.push_back(x);
                seen.insert(x);
            }
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
    }

    cout << '\n';
}
