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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_inside = INT_MAX;
    int min_inside_i = 0;

    vector<int> inside;
    vector<int> best_outside;

    for (int i = 0; i < x; ++i) {
        best_outside.push_back(a[i]);
    }

    for (int i = x; i < y; ++i) {
        inside.push_back(a[i]);
        if (a[i] < min_inside) {
            min_inside = a[i];
            min_inside_i = i - x;
        }
    }

    for (int i = y; i < n; ++i) {
        best_outside.push_back(a[i]);
    }

    vector<int> best_inside;
    for (int i = 0; i < inside.size(); ++i) {
        best_inside.push_back(inside[(min_inside_i + i) % inside.size()]);
    }

    bool inserted = false;
    for (int i = 0; i < best_outside.size(); ++i) {
        if (best_outside[i] > best_inside[0] && !inserted) {
            for (int j = 0; j < inside.size(); ++j) {
                cout << best_inside[j] << ' ';
            }
            inserted = true;
        }
        cout << best_outside[i] << ' ';
    }

    if (!inserted) {
        for (int j = 0; j < inside.size(); ++j) {
            cout << best_inside[j] << ' ';
        }
    }

    cout << '\n';
}
