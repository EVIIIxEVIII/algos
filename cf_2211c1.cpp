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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    deque<int> win_a;
    deque<int> win_b;

    set<int> win_a_els;
    set<int> win_b_els;

    for (int i = 0; i < k; ++i) {
        win_a.push_back(a[i]);
        win_a_els.insert(a[i]);

        win_b.push_back(b[i]);
        if (b[i] != -1) {
            auto it = win_b_els.insert(b[i]);
            if (!it.second) {
                cout << "NO" << '\n';
                return;
            }

            if (!win_a_els.contains(b[i])) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    int r = k;
    while (r < n) {
        int rem_a = win_a.front();
        win_a.pop_front();

        int rem_b = win_b.front();
        win_b.pop_front();

        win_a_els.erase(rem_a);
        if (rem_b != -1) win_b_els.erase(rem_b);

        if (win_b_els.contains(rem_a)) {
            cout << "NO" << '\n';
            return;
        }

        if (win_a_els.contains(rem_b)) {
            cout << "NO" << '\n';
            return;
        }

        win_a.push_back(a[r]);
        win_b.push_back(b[r]);

        win_a_els.insert(a[r]);
        if (b[r] != -1) {
            auto it = win_b_els.insert(b[r]);
            if (!it.second) {
                cout << "NO" <<'\n';
                return;
            }

            if (!win_a_els.contains(b[r])) {
                cout << "NO" << '\n';
                return;
            }
        }

        r++;
    }

    cout << "YES" << '\n';
}
