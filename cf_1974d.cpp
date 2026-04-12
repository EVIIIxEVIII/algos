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

    // we can probably think of N as 1 and S as -1
    // and we can think of W as -1 and E as 1 and we need to
    // distribute the string s into two sequences such that their sums are equal.
    // we can probably express each move as a vector <x, y> and then we need to find
    // two subsequences in S, which when added up give us S, such that the sum of these vectors are equal.

    int nth = 0, sth = 0, est = 0, wst = 0;

    vector<int> s_p;
    vector<int> n_p;
    vector<int> w_p;
    vector<int> e_p;
    for (int i = 0; i < n; ++i) {
        sth += s[i] == 'S';
        if (s[i] == 'S') s_p.push_back(i);
        nth += s[i] == 'N';
        if (s[i] == 'N') n_p.push_back(i);
        wst += s[i] == 'W';
        if (s[i] == 'W') w_p.push_back(i);
        est += s[i] == 'E';
        if (s[i] == 'E') e_p.push_back(i);
    }

    int pairs_y = min(nth, sth);
    int pairs_x = min(wst, est);

    int moves = pairs_x + pairs_y + abs(nth-sth) + abs(wst-est);
    if (moves < 2 || abs(nth-sth)%2 != 0 || abs(wst-est)%2 != 0) {
        cout << "NO" << '\n';
        return;
    }

    vector<char> ans(n);
    for (int i = 0; i < pairs_y; ++i) {
        ans[s_p.back()] = i%2 ? 'R' : 'H';
        ans[n_p.back()] = i%2 ? 'R' : 'H';
        s_p.pop_back(); n_p.pop_back();
    }

    for (int i = 0; i < pairs_x; ++i) {
        ans[e_p.back()] = i%2 ? 'H' : 'R';
        ans[w_p.back()] = i%2 ? 'H' : 'R';
        e_p.pop_back(); w_p.pop_back();
    }

    for (int i = 0; i < abs(nth-sth); ++i) {
        if (!n_p.empty()) {
            ans[n_p.back()] = i%2 ? 'R' : 'H';
            n_p.pop_back();
        } else {
            ans[s_p.back()] = i%2 ? 'R' : 'H';
            s_p.pop_back();
        }
    }

    for (int i = 0; i < abs(est-wst); ++i) {
        if (!e_p.empty()) {
            ans[e_p.back()] = i%2 ? 'R' : 'H';
            e_p.pop_back();
        } else {
            ans[w_p.back()] = i%2 ? 'R' : 'H';
            w_p.pop_back();
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout << '\n';
}
