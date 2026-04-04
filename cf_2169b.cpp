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
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n-1; ++i) {
        if (s[i] != '<' && s[i+1] != '>') {
            cout << -1 << '\n';
            return;
        }
    }

    int left = 0;
    while (left < n && s[left] != '>') {
        left++;
    }

    int right = n-1;
    while (right >= 0 && s[right] != '<') {
        right--;
    }

    right = n - 1 - right;
    cout << max(right, left) << '\n';
}
