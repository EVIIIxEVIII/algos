#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cin >> s;

        int mn = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            mn = a[mn] > a[i] ? i : mn;
            mx = a[mx] < a[i] ? i : mx;
        }

        if (s[0] == '1' || s[n-1] == '1') {
            cout << -1 << '\n';
            continue;
        }

        if (s[mn] == '1' || s[mx] == '1') {
            cout << -1 << '\n';
            continue;
        }

        cout << 5 << '\n';
        cout << 1 << ' ' << mn+1 << '\n'; // all numbers smaller than a[0] between 0 and mn
        cout << 1 << ' ' << mx+1 << '\n'; // all numbers greater than a[0] between 0 and mx
        cout << mn+1 << ' ' << n << '\n'; // all number between mn and n smaller than n
        cout << mx+1 << ' ' << n << '\n'; // all number between mx and n greater than n
        cout << min(mn+1, mx+1) << ' ' << max(mn+1, mx+1) << '\n'; // the rest of the numbers between the two
    }
    return 0;
}
