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

    vector<char> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<char> s;
    for (int i = 0; i < n; ++i) {
        if (s.empty() || s.top() != a[i]) {
            s.push(a[i]);
        } else {
            s.pop();
        }
    }

    cout << (s.empty() ? "YES" : "NO") << '\n';
}
