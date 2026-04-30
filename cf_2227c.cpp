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

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> div_2;
    vector<int> div_3;
    vector<int> div_6;
    vector<int> rest;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 6 == 0) {
            div_6.push_back(a[i]);
        } else if (a[i] % 3 == 0) {
            div_3.push_back(a[i]);
        } else if (a[i] % 2 == 0) {
            div_2.push_back(a[i]);
        } else {
            rest.push_back(a[i]);
        }
    }

    for (int div_by_6 : div_6) {
        cout << div_by_6 << ' ';
    }

    for (int div_by_2 : div_2) {
        cout << div_by_2 << ' ';
    }

    for (int r : rest) {
        cout << r << ' ';
    }

    for (int div_by_3 : div_3) {
        cout << div_by_3 << ' ';
    }

    cout << '\n';
}
