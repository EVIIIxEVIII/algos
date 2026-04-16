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
    long long n, m;
    string s;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> s;

    int l = 0, r = n - 1;
    for (char c : s) {
        if (c == 'R') {
            r--;
        } else {
            l++;
        }
    }

    reverse(s.begin(), s.end());

    vector<long long> ans;
    long long current = 1;
    for (char c : s) {
        if (c == 'R') {
            r++;
            current = current * a[r] % m;
        } else {
            l--;
            current = current * a[l] % m;
        }
        ans.push_back(current);
    }
    reverse(ans.begin(), ans.end());

    for (long long val : ans) {
        cout << val << ' ';
    }

    cout << '\n';
}
