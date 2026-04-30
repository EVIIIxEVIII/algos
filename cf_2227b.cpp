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

    string s;
    cin >> s;

    int cnt_o = 0;
    int cnt_c = 0;

    for (char c : s) {
        cnt_o += c == '(';
        cnt_c += c == ')';
    }

    if (cnt_o == cnt_c) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
