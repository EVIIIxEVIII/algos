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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    vector<bool> remove(n, false);
    for (int i = 0; i < n; ++i) {
        auto [a_i, b_i] = a[i];

        for (int j = i+1; j < n; ++j) {
            if (remove[j]) continue;

            auto [a_j, b_j] = a[j];
            if (a_i <= a_j && b_i >= b_j) {
                remove[j] = true;
            }
            if (a_i >= a_j && b_i <= b_j) {
                remove[i] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!remove[i]) {
            count++;
        }
    }
    cout << count << '\n';

    for (int i = 0; i < n; ++i) {
        if (!remove[i]) {
            cout << i+1 << ' ';
        }
    }
    cout << '\n';
}
