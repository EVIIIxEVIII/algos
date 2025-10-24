#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s;
        cin >> s;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') { count++; }
        }

        cout << count << '\n';
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') { cout << i+1 << ' '; }
        }
        cout << '\n';
    }
    return 0;
}
