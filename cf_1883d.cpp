#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int q;
    cin >> q;

    multiset<int> ls;
    multiset<int> rs;

    for (int i = 0; i < q; ++i) {
        char sign;
        int l, r;
        cin >> sign >> l >> r;

        if (sign == '+') {
            ls.insert(l);
            rs.insert(r);
        } else {
            auto it = ls.find(l);
            ls.erase(it);
            auto it_ = rs.find(r);
            rs.erase(it_);
        }

        if (ls.empty() && rs.empty()) {
            cout << "NO" << '\n';
        } else {
            cout << (*rs.begin() < *ls.rbegin() ? "YES" : "NO") << '\n';
        }
    }
}
