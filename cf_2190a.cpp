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

    string s;
    cin >> s;

    string t = s;
    sort(t.begin(), t.end());

    if (t == s) {
        cout << "Bob" << '\n';
        return;
    }


    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            count++;
        }
    }

    cout << "Alice" << '\n';
    cout << count << '\n';
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            cout << i+1 << ' ';
        }
    }

    cout << '\n';

}
