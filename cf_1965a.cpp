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

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // define a free move as a move where the player P can choose what value to pick
    // where the value can be > 1. The player who has the first free move wins.

    sort(a.begin(), a.end());

    if (a[0] != 1) {
        cout << "Alice" << '\n';
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1] && a[i] != a[i-1] + 1) {
            cout << (a[i-1]%2 ? "Bob" : "Alice") << '\n';
            return;
        }
    }

    cout << (a[n-1]%2 ? "Alice" : "Bob") << '\n';
}
