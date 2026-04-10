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
    string s; cin >> s;

    // 1 2 3 4 5 -> if all p
    // 5 4 3 2 1 -> if all s

    // either all p and at the end s
    // or all s and at the end p

    int cnt_s = 0;
    int cnt_p = 0;

    for (char c : s) {
        cnt_s += c == 's';
        cnt_p += c == 'p';
    }

    if (cnt_s == 0 || cnt_p == 0) {
        cout << "YES" << '\n';
    } else if (cnt_s > 1 && cnt_p > 1) {
        cout << "NO" << '\n';
    } else {
        bool ans = false;

        if (cnt_p == 1) {
            ans = (s[n-1] == 'p' || s[0] == 'p');
        }
        if (cnt_s == 1) {
            ans = (s[n-1] == 's' || s[0] == 's');
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
