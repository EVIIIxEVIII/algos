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

    vector<int> p(n);
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the order in the array a is probably what validates it...


    int l1 = 0;

    for (int l2 = 0; l2 < n; ++l2) {
        while (l1 < n && p[l1] != a[l2]) {
            l1++;
        }

        if (l1 >= n) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';

}
