#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[(i + 1) % n]) {
                count++;
            }
        }

        if (count == n) {
            cout << n << '\n';
        } else if (count == 0) {
            cout << 1 << '\n';
        } else {
            cout << count + 1 << '\n';
        }
    }

    return 0;
}
