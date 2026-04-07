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
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }


    vector<pair<int,int>> moves;

    for (int i = 0; i < n; ++i) {
        int max_i = 0;
        int max_val = 0;
        for (int j = 0; j < n - i; ++j) {
            if (a[j] > max_val) {
                max_val = a[j];
                max_i = j;
            }
        }

        for (int j = max_i; j < n - i - 1; ++j) {
            swap(a[j], a[j+1]);
            moves.push_back({1, j+1});
        }
    }

    for (int i = 0; i < n; ++i) {
        int max_i = 0;
        int max_val = 0;
        for (int j = 0; j < n - i; ++j) {
            if (b[j] > max_val) {
                max_val = b[j];
                max_i = j;
            }
        }
        for (int j = max_i; j < n - i - 1; ++j) {
            swap(b[j], b[j+1]);
            moves.push_back({2, j+1});
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (b[i] < a[i]) {
            moves.push_back({3, i+1});
        }
    }

    cout << moves.size() << '\n';
    for (auto [t, i] : moves) {
        cout << t << ' ' << i << '\n';
    }
}
