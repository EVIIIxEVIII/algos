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

    cnt_s -= s[0] == 's';
    cnt_p -= s[n-1] == 'p';

    if (cnt_s >= 1 && cnt_p >= 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}
