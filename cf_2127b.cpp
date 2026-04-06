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
    int x; cin >> x;

    string s;
    cin >> s;

    int walls = 0;
    int left_closest = 0;
    int right_closest = n;

    for (char c : s) {
        if (c == '#') {
            walls++;
        }
    }

    for (int i = 0; i < x-1; ++i) {
        if (s[i] == '#') {
            left_closest = i+1;
        }
    }

    for (int i = x; i < n; ++i) {
        if (s[i] == '#') {
            right_closest = i+1;
            break;
        }
    }

    if (walls == 0) {
        cout << 1 << '\n';
        return;
    }

    // options:
    // n - x + 1, x + 1, max(left_closest + 1, n - right_closest + 1)
    // grind through right, grind throught left, pick an opposite side from the first set wall

    cout << min({n-x+1, x, max(left_closest + 1, n - right_closest + 2)}) << '\n';
}
