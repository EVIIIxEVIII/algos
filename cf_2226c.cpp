#include <algorithm>
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

    multiset<int> m_set;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m_set.insert(a[i]);
    }

    // will be at least 0

    // i = 0 for b[0] = a[0] to get 0
    // if b > a, then a % b == a
    // a = k * b + r, with k >= 1 and 0 <= r < b
    // set k = 1 and get a = b + r =>
    // b = a - r
    // for that r < b => r < a - r => 2*r < a => r < floor(a/2)
    // so we have values from 0 to floor(a-1/2)

    //for (int a_i : a) {
    //    cout << a_i << ' ';
    //}
    //cout << '\n';

    auto check = [](int t, multiset<int> m_set) {
        for (int x = t - 1; x >= 0; --x) {
            auto exact = m_set.find(x);

            if (exact != m_set.end()) {
                m_set.erase(exact);
                continue;
            }

            auto it = m_set.lower_bound(2 * x + 1);
            if (it == m_set.end()) {
                return false;
            }

            m_set.erase(it);
        }

        return true;
    };

    // TTTFFF
    int l = 0;
    int r = n;

    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (check(m, m_set)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';
}

